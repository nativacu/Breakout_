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

	private:
		float mVertices[32]{
			// positions          // colors           // texture coords
			0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
			0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
			-0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
			-0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
		};

		float mIndices[6];
		std::string mTexturePath;
	};
}

#endif // !_BLOCK_HPP_

