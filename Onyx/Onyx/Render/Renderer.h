
/*
	2019.05.24
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_RENDERER_H

#define _CLASS_ONYX_RENDER_RENDERER_H

#include "../Vulkan.h"

namespace Onyx::Render
{
	class Renderer
	{
	private:
		
		
	public:
		Renderer();
		Renderer(const Renderer &sSrc);
		Renderer(Renderer &&sSrc);
		~Renderer();
		
	public:
		Renderer &operator=(const Renderer &sSrc);
		Renderer &operator=(Renderer &&sSrc);
		
	public:
		void render(VkCommandBuffer vkCommandBuffer);
	};
}

#endif