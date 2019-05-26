
/*
	2019.05.24
	Created by AcrylicShrimp.
*/

#include "Renderer.h"

namespace Onyx::Render
{
	Renderer::Renderer()
	{
		
	}
	
	Renderer::Renderer(const Renderer &sSrc)
	{
		
	}
	
	Renderer::Renderer(Renderer &&sSrc)
	{
		
	}
	
	Renderer::~Renderer()
	{
		
	}
	
	Renderer &Renderer::operator=(const Renderer &sSrc)
	{
		if (&sSrc == this)
			return *this;
		

		
		return *this;
	}
	
	Renderer &Renderer::operator=(Renderer &&sSrc)
	{
		if (&sSrc == this)
			return *this;
		


		return *this;
	}
}