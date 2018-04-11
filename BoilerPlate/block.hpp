#include "gameObject.hpp"

#pragma once
#ifndef _BLOCK_HPP_
#define _BLOCK_HPP_

namespace game
{
	class component;
	class block : public engine::core::gameObject
	{
	public:
		block();
		float* get_vertices() override;

	private:
		float mVertices[36]{
			// positions          // colors					// texture coords
			0.08f,  0.08f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
			0.08f, -0.08f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,	1.0f, 0.0f,   // bottom right
			-0.08f, -0.08f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,	 0.0f, 0.0f,   // bottom left
			-0.08f,  0.08f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 1.0f    // top left 
		};
	};
}

#endif // !_BLOCK_HPP_