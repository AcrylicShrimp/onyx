
/*
	2019.05.05
	Created by AcrylicShrimp.
*/

#include "Onyx.h"

#include "./Render/Material.h"
#include "./Render/Mesh.h"
#include "./Render/MeshManager.h"
#include "./Transform/Vecs.h"
#include "./Transform/Mats.h"
#include "./Transform/Transform.h"

#include <fstream>
#include <string>
#include <tuple>
#include <unordered_map>

int main()
{
	using namespace Onyx::Transform;

	Onyx::Onyx sInstance{Onyx::Version{"test", 0, 0, 0}};

	auto pWindow{sInstance.displayMgr().createWindow("main")};
	pWindow->create(Onyx::Display::Window::Style::Standard, L"Onyx test");

	auto pContext{sInstance.contextMgr().createContext(pWindow)};
	{
		auto fReadBinary{[](std::string_view sPath)
		{
			std::ifstream sInput{sPath.data(), std::ios_base::ate | std::ios_base::binary};
			std::vector<char> sResult(static_cast<std::size_t>(sInput.tellg()));

			sInput.seekg(0).read(sResult.data(), static_cast<std::streamsize>(sResult.size()));

			return sResult;
		}};

		auto pShader{pContext->shaderMgr().createShader("color_forward")};

		auto sVertexShaderBinary{fReadBinary("vert.spv")};
		auto sFragmentShaderBinary{fReadBinary("frag.spv")};

		pShader->attachStage(Onyx::Render::Shader::Stage::Vertex, sVertexShaderBinary.size(), reinterpret_cast<std::uint32_t *>(sVertexShaderBinary.data()), "main");
		pShader->attachStage(Onyx::Render::Shader::Stage::Fragment, sFragmentShaderBinary.size(), reinterpret_cast<std::uint32_t *>(sFragmentShaderBinary.data()), "main");

		auto sCubeMeshBinary{fReadBinary("cube.obj")};
		auto sConeMeshBinary{fReadBinary("cone.obj")};

		std::unordered_map<std::uint32_t, std::uint32_t> sLocationOffsetMap;
		sLocationOffsetMap[4] = sizeof(float) * 0;
		sLocationOffsetMap[5] = sizeof(float) * 3;
		sLocationOffsetMap[6] = sizeof(float) * 5;

		auto pCubeMesh{pContext->meshMgr().loadMeshOBJ(std::string{sCubeMeshBinary.cbegin(), sCubeMeshBinary.cend()})};
		auto pConeMesh{pContext->meshMgr().loadMeshOBJ(std::string{sConeMeshBinary.cbegin(), sConeMeshBinary.cend()})};
		Onyx::Render::Material sMaterial{pContext.get(), pShader, &pCubeMesh->sMeshLayout, sLocationOffsetMap};

		std::vector<Mat44<float>> sTranformList
		{
			Onyx::Transform::Transform::translate(.0f, .0f, -4.f) % Onyx::Transform::Transform::perspective(1.333f, 45.f / 180.f * 3.141592f, 0.01f, 100.f),
			Onyx::Transform::Transform::translate(1.f, .0f, -4.f) % Onyx::Transform::Transform::perspective(1.333f, 45.f / 180.f * 3.141592f, 0.01f, 100.f),
			Onyx::Transform::Transform::translate(2.f, .0f, -4.f) % Onyx::Transform::Transform::perspective(1.333f, 45.f / 180.f * 3.141592f, 0.01f, 100.f)
		};
		std::vector<std::tuple<Onyx::Render::Material *, Onyx::Render::Mesh *>> sRenderableList
		{
			std::make_tuple(&sMaterial, pCubeMesh.get()),
			std::make_tuple(&sMaterial, pConeMesh.get()),
			std::make_tuple(&sMaterial, pCubeMesh.get())
		};

		pWindow->setVisibility(Onyx::Display::Window::Visibility::VisibleDefault);

		while (pWindow->loopEventAvailable())
			pContext->render(sTranformList, sRenderableList);

		pWindow->setVisibility(Onyx::Display::Window::Visibility::Invisible);
	}
	pContext = nullptr;
	
	pWindow->destroy();
}