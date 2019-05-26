
/*
	2019.05.05
	Created by AcrylicShrimp.
*/

#include "Onyx.h"

#include "./Render/Material.h"

#include <fstream>

int main()
{
	Onyx::Onyx sInstance{Onyx::Version{"test", 0, 0, 0}};

	auto pWindow{sInstance.displayMgr().createWindow("main")};
	pWindow->create(Onyx::Display::Window::Style::Standard, L"Onyx test");

	auto pContext{sInstance.contextMgr().createContext(pWindow)};
	{
		auto pMesh{pContext->meshMgr().createMesh()};
		auto pShader{pContext->shaderMgr().createShader("color_forward")};

		auto fReadBinary{[](std::string_view sPath)
		{
			std::ifstream sInput{sPath.data(), std::ios_base::ate | std::ios_base::binary};
			std::vector<char> sResult(static_cast<std::size_t>(sInput.tellg()));

			sInput.seekg(0).read(sResult.data(), static_cast<std::streamsize>(sResult.size()));

			return sResult;
		}};

		auto sVertexShaderBinary{fReadBinary("vert.spv")};
		auto sFragmentShaderBinary{fReadBinary("frag.spv")};

		pShader->attachStage(Onyx::Render::Shader::Stage::Vertex, sVertexShaderBinary.size(), reinterpret_cast<std::uint32_t *>(sVertexShaderBinary.data()));
		pShader->attachStage(Onyx::Render::Shader::Stage::Fragment, sFragmentShaderBinary.size(), reinterpret_cast<std::uint32_t *>(sFragmentShaderBinary.data()));

		Onyx::Render::Material sMaterial{pContext.get(), pMesh.get(), pShader};

		pWindow->setVisibility(Onyx::Display::Window::Visibility::VisibleDefault);

		while (pWindow->loopEventAvailable())
			pContext->render(sMaterial);

		pWindow->setVisibility(Onyx::Display::Window::Visibility::Invisible);
	}
	pContext = nullptr;
	
	pWindow->destroy();
}