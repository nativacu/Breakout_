#include "gameObject.hpp"

#pragma once
#ifndef _BALL_HPP_
#define _BALL_HPP_

namespace game
{
	class component;
	class ball : public engine::core::gameObject
	{
	public:
		ball();

	private:
		float mVertices[32]{
			// positions          // colors           // texture coords
			0.2f,  0.2f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
			0.2f, -0.2f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
			-0.2f, -0.2f, 0.0f,  0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
			-0.2f,  0.2f, 0.0f,  1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
		};

		float mIndices[6];
		std::string mTexturePath;
	};
}

#endif // !_BALL_HPP_

