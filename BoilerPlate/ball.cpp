#include "ball.hpp"

game::ball::ball()
{
	mTexturePath = "assets/ball.png";
	mIsUsingAlpha = true;

	engine::components::positionComponent *positionComponent =
		new engine::components::positionComponent("position", engine::math::vector4(0.0f, -0.9f + 0.06f, 0.0f, 0.0f));

	attach_component(positionComponent);

	mIsFree = false;
}

float * game::ball::get_vertices()
{
	float mHey[16];
	return mVertices;
}

bool game::ball::get_status()
{
	return mIsFree;
}

bool game::ball::get_is_going_down()
{
	return mIsGoingDown;
}

void game::ball::release_ball()
{
	mIsFree = true;
}

void game::ball::set_is_going_down(bool orientation)
{
	mIsGoingDown = orientation;
}
