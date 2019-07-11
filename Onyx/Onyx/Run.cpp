
/*
	2019.05.05
	Created by AcrylicShrimp.
*/

#include "Onyx.h"

#include "./Render/Object.h"
#include "./Transform/Vecs.h"
#include "./Transform/Mats.h"
#include "./Transform/Transform.h"

#include <fstream>
#include <string>

int main()
{
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

		auto sMeshBinary{fReadBinary("cube_tri.obj")};

		auto pMesh{pContext->meshMgr().loadMeshOBJ(std::string{sMeshBinary.cbegin(), sMeshBinary.cend()})};
		auto pShader{pContext->shaderMgr().createShader("color_forward")};

		auto sVertexShaderBinary{fReadBinary("vert.spv")};
		auto sFragmentShaderBinary{fReadBinary("frag.spv")};

		pShader->attachStage(Onyx::Render::Shader::Stage::Vertex, sVertexShaderBinary.size(), reinterpret_cast<std::uint32_t *>(sVertexShaderBinary.data()));
		pShader->attachStage(Onyx::Render::Shader::Stage::Fragment, sFragmentShaderBinary.size(), reinterpret_cast<std::uint32_t *>(sFragmentShaderBinary.data()));

		Onyx::Transform::Transform sTransform;
		sTransform.sMatrix = Onyx::Transform::Transform::scale(.2f);

		Onyx::Render::Object sObject{pContext.get(), pMesh.get(), pShader, sTransform.sMatrix};

		pWindow->setVisibility(Onyx::Display::Window::Visibility::VisibleDefault);

		while (pWindow->loopEventAvailable())
			pContext->render(sObject);

		pWindow->setVisibility(Onyx::Display::Window::Visibility::Invisible);
	}
	pContext = nullptr;
	
	pWindow->destroy();
}