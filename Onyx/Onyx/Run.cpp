
/*
	2019.05.05
	Created by AcrylicShrimp.
*/

#include "Onyx.h"

#include "./Render/TEST__TriangleRenderPass.h"

int main()
{
	Onyx::Onyx sInstance{Onyx::Version{"test", 0, 0, 0}};

	auto pWindow{sInstance.sDisplayMgr.createWindow("main")};
	pWindow->create(Onyx::Display::Window::Style::Standard, L"Onyx test");

	auto pContext{sInstance.sContextMgr.createContext(pWindow)};
	{
		Onyx::Render::TEST__TriangleRenderPass sTriangleRenderPass{pContext.get()};

		pWindow->setVisibility(Onyx::Display::Window::Visibility::VisibleDefault);

		while (pWindow->loopEventAvailable())
			pContext->render(sTriangleRenderPass.vulkanPipeline(), sTriangleRenderPass.vulkanRenderPass(), sTriangleRenderPass.vulkanFramebufferList());

		pWindow->setVisibility(Onyx::Display::Window::Visibility::Invisible);
	}
	pContext = nullptr;
	
	pWindow->destroy();
}