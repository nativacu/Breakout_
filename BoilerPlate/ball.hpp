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
		float* get_vertices() override;
		bool get_status();
		bool get_is_going_down();
		void release_ball();
		void set_is_going_down(bool orientation);
		void ball_renderer();

	private:
		float mVertices[36]{
			// positions          // colors					// texture coords
			0.02f,  0.03f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
			0.02f, -0.03f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,	 1.0f, 0.0f,   // bottom right
			-0.02f, -0.03f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,	 0.0f, 0.0f,   // bottom left
			-0.02f,  0.03f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 1.0f    // top left 
		};

		bool mIsFree = false;
		bool mIsGoingDown = false;
	};
}

#endif // !_BALL_HPP_