#pragma once
#include "gameObject.hpp"
#include "positionComponent.hpp"

#pragma once
#ifndef _PADDLE_HPP_
#define _PADDLE_HPP_

namespace game {
	class component;
	class paddle : public engine::core::gameObject
	{
	public:
		paddle();
		float* get_vertices() override;

	private:
		float mVertices[36]{
			// positions          // colors					// texture coords
			0.1f,  0.03f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
			0.1f, -0.03f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,	 1.0f, 0.0f,   // bottom right
			-0.1f, -0.03f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,	 0.0f, 0.0f,   // bottom left
			-0.1f,  0.03f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 1.0f    // top left 
		};
	};
}

#endif // !_PADDLE_HPP_
