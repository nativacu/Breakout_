#pragma once
#ifndef _VERTICES_COMPONENT_HPP_
#define _VERTICES_COMPONENT_HPP_

#include "component.hpp"

const int MAX_VERTICES_COUNT = 36;

namespace engine
{
	namespace core
	{
		namespace components
		{
			class verticesComponent :  public engine::core::component
			{
			public:
				verticesComponent();
				verticesComponent(const std::string pName, float pVertices[MAX_VERTICES_COUNT]);
				float* get_vertices();
			private:
				float mObjectVertices[MAX_VERTICES_COUNT];
			};
		}
	}
}

#endif // !_VERTICES_COMPONENT_HPP_

