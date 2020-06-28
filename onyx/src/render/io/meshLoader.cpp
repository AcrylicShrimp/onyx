
#include "onyx/includes/render/io/meshLoader.h"

#include "onyx/includes/core/vulkan.h"
#include "onyx/includes/render/core/mesh.h"
#include "onyx/includes/render/core/meshElement.h"

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <iterator>
#include <optional>
#include <sstream>
#include <stdexcept>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

namespace onyx::render::io {
	std::unique_ptr<::onyx::render::core::Mesh>
		MeshLoader::loadMeshOBJ(const ::onyx::core::Context *pContext, const std::string &sContent)
	{
		std::istringstream sStringStream{sContent};

		auto fParseNextLine{[&sStringStream]() {
			std::istream_iterator<std::string> iBegin{sStringStream}, iEnd{};

			if (iBegin == iEnd) return std::optional<std::tuple<std::string, std::vector<std::string>>>{};

			auto		sCommand{*iBegin};
			std::string sLine;

			std::getline(sStringStream, sLine);
			std::istringstream sLineStream{sLine};

			return std::optional<std::tuple<std::string, std::vector<std::string>>>{std::make_tuple(
				sCommand,
				std::vector<std::string>{
					std::istream_iterator<std::string>{sLineStream},
					std::istream_iterator<std::string>{}})};
		}};

		std::size_t		   nVertexCount{0};
		std::vector<float> sPositionList;
		std::vector<float> sUVList;
		std::vector<float> sNormalList;
		std::vector<float> sUnrolledPosition;
		std::vector<float> sUnrolledUV;
		std::vector<float> sUnrolledNormal;

		for (auto sLine{fParseNextLine()}; sLine; sLine = fParseNextLine()) {
			using namespace std::string_literals;

			const auto &sCommand{std::get<0>(*sLine)};
			const auto &sParamList{std::get<1>(*sLine)};

			if (sCommand == "v"s) {
				if (sParamList.size() != 3 && sParamList.size() != 4) throw std::runtime_error{"wrong format"};

				sPositionList.emplace_back(std::stof(sParamList[0]));
				sPositionList.emplace_back(std::stof(sParamList[1]));
				sPositionList.emplace_back(std::stof(sParamList[2]));
			}
			else if (sCommand == "vt"s) {
				if (sParamList.size() != 1 && sParamList.size() != 2 && sParamList.size() != 3)
					throw std::runtime_error{"wrong format"};

				sUVList.emplace_back(std::stof(sParamList[0]));

				if (sParamList.size() != 1) sUVList.emplace_back(std::stof(sParamList[1]));
				else
					sUVList.emplace_back(.0f);
			}
			else if (sCommand == "vn"s) {
				if (sParamList.size() != 3) throw std::runtime_error{"wrong format"};

				sNormalList.emplace_back(std::stof(sParamList[0]));
				sNormalList.emplace_back(std::stof(sParamList[1]));
				sNormalList.emplace_back(std::stof(sParamList[2]));

				auto &nX{*(sNormalList.end() - 3)};
				auto &nY{*(sNormalList.end() - 2)};
				auto &nZ{*(sNormalList.end() - 1)};

				auto nLengthInv{1.f / std::sqrt(nX * nX + nY * nY + nZ * nZ)};

				nX *= nLengthInv;
				nY *= nLengthInv;
				nZ *= nLengthInv;
			}
			else if (sCommand == "f"s) {
				if (sParamList.size() < 3) throw std::runtime_error{"wrong format"};

				std::vector<std::tuple<std::int64_t, std::int64_t, std::int64_t>> sIndexList;

				for (const auto &sParam: sParamList) {
					auto fTrim{[](std::string &sString) {
						sString.erase(sString.begin(), std::find_if(sString.begin(), sString.end(), [](char nChar) {
										  return !std::isspace(nChar);
									  }));
						sString.erase(
							std::find_if(
								sString.rbegin(),
								sString.rend(),
								[](char nChar) {
									return !std::isspace(nChar);
								})
								.base(),
							sString.end());

						return sString;
					}};
					auto fSplit{[](const std::string &sString, char nDelimiter) {
						std::vector<std::string> sResult;

						for (std::size_t nOffset{0}, nLength{sString.length()}; nOffset < nLength;
							 nOffset += sResult.back().length() + 1)
							sResult.emplace_back(sString.substr(nOffset, sString.find(nDelimiter, nOffset) - nOffset));

						return sResult;
					}};

					auto sIndexStringList{fSplit(sParam, '/')};

					if (sIndexStringList.size() != 1 && sIndexStringList.size() != 2 && sIndexStringList.size() != 3)
						throw std::runtime_error{"wrong format"};

					sIndexList.emplace_back(
						std::stoll(fTrim(sIndexStringList[0])),
						sIndexStringList.size() < 2 ? 0 : std::stoll(fTrim(sIndexStringList[1])),
						sIndexStringList.size() < 3 ? 0 : std::stoll(fTrim(sIndexStringList[2])));
				}

				for (std::size_t nIndex{1}, nMaxIndex{sIndexList.size() - 1}; nIndex < nMaxIndex; ++nIndex) {
					auto fPushData{[&sPositionList,
									&sUVList,
									&sNormalList,
									&sUnrolledPosition,
									&sUnrolledUV,
									&sUnrolledNormal](
									   const std::tuple<std::int64_t, std::int64_t, std::int64_t> &sIndexTuple) {
						auto nVertexIndex{std::get<0>(sIndexTuple)};
						auto nUVIndex{std::get<1>(sIndexTuple)};
						auto nNormalIndex{std::get<2>(sIndexTuple)};

						if (nVertexIndex < 0) {
							if (sPositionList.size() < static_cast<std::size_t>(-nVertexIndex * 3))
								throw std::runtime_error{"wrong format"};

							sUnrolledPosition.emplace_back(
								sPositionList[(sPositionList.size() + static_cast<std::size_t>(nVertexIndex) * 3) + 0]);
							sUnrolledPosition.emplace_back(
								sPositionList[(sPositionList.size() + static_cast<std::size_t>(nVertexIndex) * 3) + 1]);
							sUnrolledPosition.emplace_back(
								sPositionList[(sPositionList.size() + static_cast<std::size_t>(nVertexIndex) * 3) + 2]);
						}
						else if (nVertexIndex > 0) {
							if (sPositionList.size() <= static_cast<std::size_t>((nVertexIndex - 1) * 3))
								throw std::runtime_error{"wrong format"};

							sUnrolledPosition.emplace_back(
								sPositionList[static_cast<std::size_t>(nVertexIndex - 1) * 3 + 0]);
							sUnrolledPosition.emplace_back(
								sPositionList[static_cast<std::size_t>(nVertexIndex - 1) * 3 + 1]);
							sUnrolledPosition.emplace_back(
								sPositionList[static_cast<std::size_t>(nVertexIndex - 1) * 3 + 2]);
						}
						else
							throw std::runtime_error{"wrong format"};

						if (nUVIndex < 0) {
							if (sUVList.size() < static_cast<std::size_t>(-nUVIndex * 2))
								throw std::runtime_error{"wrong format"};

							sUnrolledUV.emplace_back(
								sUVList[(sUVList.size() + static_cast<std::size_t>(nUVIndex) * 2) + 0]);
							sUnrolledUV.emplace_back(
								sUVList[(sUVList.size() + static_cast<std::size_t>(nUVIndex) * 2) + 1]);
						}
						else if (nUVIndex > 0) {
							if (sUVList.size() <= static_cast<std::size_t>((nUVIndex - 1) * 2))
								throw std::runtime_error{"wrong format"};

							sUnrolledUV.emplace_back(sUVList[static_cast<std::size_t>(nUVIndex - 1) * 2 + 0]);
							sUnrolledUV.emplace_back(sUVList[static_cast<std::size_t>(nUVIndex - 1) * 2 + 1]);
						}

						if (nNormalIndex < 0) {
							if (sNormalList.size() < static_cast<std::size_t>(-nNormalIndex * 3))
								throw std::runtime_error{"wrong format"};

							sUnrolledNormal.emplace_back(
								sNormalList[(sNormalList.size() + static_cast<std::size_t>(nNormalIndex) * 3) + 0]);
							sUnrolledNormal.emplace_back(
								sNormalList[(sNormalList.size() + static_cast<std::size_t>(nNormalIndex) * 3) + 1]);
							sUnrolledNormal.emplace_back(
								sNormalList[(sNormalList.size() + static_cast<std::size_t>(nNormalIndex) * 3) + 2]);
						}
						else if (nNormalIndex > 0) {
							if (sNormalList.size() <= static_cast<std::size_t>((nNormalIndex - 1) * 3))
								throw std::runtime_error{"wrong format"};

							sUnrolledNormal.emplace_back(
								sNormalList[static_cast<std::size_t>(nNormalIndex - 1) * 3 + 0]);
							sUnrolledNormal.emplace_back(
								sNormalList[static_cast<std::size_t>(nNormalIndex - 1) * 3 + 1]);
							sUnrolledNormal.emplace_back(
								sNormalList[static_cast<std::size_t>(nNormalIndex - 1) * 3 + 2]);
						}
					}};

					fPushData(sIndexList[0]);
					fPushData(sIndexList[nIndex]);
					fPushData(sIndexList[nIndex + 1]);

					nVertexCount += 3;
				}
			}
		}

		std::vector<::onyx::render::core::MeshElement> sMeshElementVec{
			::onyx::render::core::MeshElement{
				VkFormat::VK_FORMAT_R32G32B32_SFLOAT,
				sizeof(float) * sUnrolledPosition.size(),
				sUnrolledPosition.data()},
			::onyx::render::core::MeshElement{
				VkFormat::VK_FORMAT_R32G32_SFLOAT,
				sizeof(float) * sUnrolledUV.size(),
				sUnrolledUV.data()},
			::onyx::render::core::MeshElement{
				VkFormat::VK_FORMAT_R32G32B32_SFLOAT,
				sizeof(float) * sUnrolledNormal.size(),
				sUnrolledNormal.data()},
		};

		return std::make_unique<::onyx::render::core::Mesh>(pContext, std::move(sMeshElementVec));
	}
}	 // namespace onyx::render::io