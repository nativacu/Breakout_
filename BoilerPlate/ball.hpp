#include "gameObject.hpp"
#include "positionComponent.hpp"

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
		ball(engine::math::vector4 velocity);
		float* get_vertices() override;
		bool get_status();
		void release_ball();
		float get_radius();
		engine::math::vector4 move_ball();

	private:
		float mVertices[36]{
			// positions          // colors					// texture coords
			0.02f,  0.03f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
			0.02f, -0.03f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,	 1.0f, 0.0f,   // bottom right
			-0.02f, -0.03f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,	 0.0f, 0.0f,   // bottom left
			-0.02f,  0.03f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 1.0f    // top left 
		};

		float radius;
		bool mIsFree;
	};
}

#endif // !_BALL_HPP_