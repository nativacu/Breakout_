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
		float* get_vertices();
		std::string getTexturePath();

	private:
		float mVertices[36]{
			// positions          // colors					// texture coords
			0.05f,  0.05f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
			0.05f, -0.05f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,	 1.0f, 0.0f,   // bottom right
			-0.05f, -0.05f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,	 0.0f, 0.0f,   // bottom left
			-0.05f,  0.05f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 1.0f    // top left 
		};

		float mIndices[6];
		std::string mTexturePath;
	};
}

#endif // !_BALL_HPP_