
/*
	2019.05.25
	Created by AcrylicShrimp.
*/

#include "MeshManager.h"

namespace Onyx::Render
{
	MeshManager::MeshManager(Context *pContext) :
		SubContextManager{pContext}
	{

	}

	MeshManager::~MeshManager()
	{

	}

	std::unique_ptr<Mesh> MeshManager::createMesh()
	{
		std::vector<std::tuple<std::string, Mesh::Data>> sMeshDataList
		{
			std::make_tuple(std::string{"position"}, Mesh::Data{VkFormat::VK_FORMAT_R32G32_SFLOAT, 0}),
			std::make_tuple(std::string{"color"}, Mesh::Data{VkFormat::VK_FORMAT_R32G32B32_SFLOAT, sizeof(float) * 4})
		};

		std::vector<float> sBufferDataList
		{
			-.5f, -.5f, .0f, .0f,
			1.f, .0f, .0f, .0f,

			-.5f, .5f, .0f, .0f,
			.0f, 1.f, .0f, .0f,

			.5f, .5f, .0f, .0f,
			.0f, .0f, 1.f, .0f,



			.5f, .5f, .0f, .0f,
			.0f, .0f, 1.f, .0f,
			
			.5f, -.5f, .0f, .0f,
			1.f, 1.f, 1.f, .0f,
			
			-.5f, -.5f, .0f, .0f,
			1.f, .0f, .0f, .0f
		};

		return std::make_unique<Mesh>(this, sizeof(float) * 8, 6, sMeshDataList, static_cast<std::uint32_t>(sizeof(float) * sBufferDataList.size()), sBufferDataList.data());
	}
}