#include "verticesComponent.hpp"

engine::core::components::verticesComponent::verticesComponent()
{
}

engine::core::components::verticesComponent::verticesComponent(const std::string pName, float pVertices[MAX_VERTICES_COUNT])
{
	mName = pName;

	for (int i = 0; i < 36; i++)
	{
		mObjectVertices[i] = pVertices[i];
	}
}

float * engine::core::components::verticesComponent::get_vertices()
{
	return mObjectVertices;
}
