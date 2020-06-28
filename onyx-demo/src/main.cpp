
#include "onyx/includes/common/version.h"
#include "onyx/includes/core/context.h"
#include "onyx/includes/core/deviceInfo.h"
#include "onyx/includes/onyx.h"
#include "onyx/includes/render/core/material.h"
#include "onyx/includes/render/core/mesh.h"
#include "onyx/includes/render/core/meshElement.h"
#include "onyx/includes/render/core/shader.h"
#include "onyx/includes/render/io/meshLoader.h"

#include <cstdint>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string_view>
#include <tuple>
#include <vector>

int main()
{
	onyx::Onyx sInstance{onyx::common::Version{"test", 0, 0, 1}};

	std::cout << "Engine initialized." << std::endl;
	std::cout << "Engine version: " << sInstance.sVersion.sName << " v" << sInstance.sVersion.nMajor << "."
			  << sInstance.sVersion.nMinor << "." << sInstance.sVersion.nPatch << std::endl;

	auto pWindow{sInstance.displayMgr().createWindow("main")};

	pWindow->create(onyx::display::Window::Style::Standard, onyx::display::Window::Region{200, 200, 800, 800}, "Test");

	auto pContext{sInstance.contextMgr().createContext(pWindow)};
	std::cout << pContext->deviceInfo()->properties().deviceName << std::endl;

	auto fReadBinary{[](std::string_view sPath) {
		std::ifstream sInput{sPath.data(), std::ios_base::ate | std::ios_base::binary};

		if (!sInput.is_open()) throw std::runtime_error{"unable to open the given path"};

		std::vector<char> sResult(static_cast<std::size_t>(sInput.tellg()));
		sInput.seekg(0).read(sResult.data(), static_cast<std::streamsize>(sResult.size()));

		return sResult;
	}};
	auto fMakeMesh([&pContext, &fReadBinary](std::string_view sPath) {
		auto sBinary{fReadBinary(sPath)};
		return onyx::render::io::MeshLoader::loadMeshOBJ(pContext.get(), std::string(sBinary.cbegin(), sBinary.cend()));
	});
	auto fMakeShader([&pContext, &fReadBinary](std::string_view sVertexPath, std::string_view sFragmentPath) {
		auto sVertexBinary{fReadBinary(sVertexPath)};
		auto sFragmentBinary{fReadBinary(sFragmentPath)};
		auto pShader{std::make_unique<onyx::render::core::Shader>(pContext.get())};

		pShader->attachVertexStage(
			sVertexBinary.size(),
			reinterpret_cast<const std::uint32_t *>(sVertexBinary.data()),
			"main");
		pShader->attachFragmentStage(
			sFragmentBinary.size(),
			reinterpret_cast<const std::uint32_t *>(sFragmentBinary.data()),
			"main");

		return pShader;
	});

	// auto pConeMesh{fMakeMesh("/Users/ashrimp/Devel/Staging/onyx/onyx-demo/assets/cone.obj")};
	auto						 pCubeMesh{fMakeMesh("/Users/ashrimp/Devel/Staging/onyx/onyx-demo/assets/cube.obj")};
	auto						 pShader{fMakeShader(
		"/Users/ashrimp/Devel/Staging/onyx/onyx-demo/assets/vert.spv",
		"/Users/ashrimp/Devel/Staging/onyx/onyx-demo/assets/frag.spv")};
	onyx::render::core::Material sMaterial{
		pContext.get(),
		pShader.get(),
		pCubeMesh->stride(),
		std::vector<std::tuple<std::uint32_t, std::uint32_t>>{
			std::make_tuple<std::uint32_t, std::uint32_t>(0, 0),
			std::make_tuple<std::uint32_t, std::uint32_t>(1, sizeof(float) * 3),
			std::make_tuple<std::uint32_t, std::uint32_t>(2, sizeof(float) * 5)}};

	pWindow->setVisibility(onyx::display::Window::Visibility::VisibleDefault);

	std::vector<std::tuple<const onyx::render::core::Material *, const onyx::render::core::Mesh *>> sMaterialMeshVec;

	sMaterialMeshVec.emplace_back(&sMaterial, pCubeMesh.get());

	while (pWindow->loopEventAvailable()) pContext->renderingMgr().render(sMaterialMeshVec);

	pWindow->destroy();

	return 0;
}