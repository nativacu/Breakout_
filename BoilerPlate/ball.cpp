#include "ball.hpp"

game::ball::ball()
{
	mTexturePath = "assets/ball.png";
	mIsUsingAlpha = true;

	engine::components::positionComponent *positionComponent =
		new engine::components::positionComponent("position", engine::math::vector4(0.0f, -0.9f + 0.06f, 0.0f, 0.0f));

	attach_component(positionComponent);

	mIsFree = false;
	mVelocity = engine::math::vector4(0.05f, 0.05f, 0.0f, 0.0f);
}

game::ball::ball(engine::math::vector4 velocity)
{
}

float * game::ball::get_vertices()
{
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

engine::math::vector4 game::ball::move_ball()
{
	engine::math::vector4 currentBallPosition = get_component("position")->get_position();
	// If not stuck to player board
	if (mIsFree)
	{
		// Move the ball
		currentBallPosition += mVelocity;

		//get_component("position")->set_position(currentBallPosition);

		// Then check if outside window bounds and if so, reverse velocity and restore at correct position
		if (/*get_component("position")->get_position().x*/ currentBallPosition.x <= 1.0f)
		{
			mVelocity.x = -mVelocity.x;

			//engine::math::vector4 tempPosition = get_component("position")->get_position();
			currentBallPosition.x = 0.0f;

			//get_component("position")->set_position(tempPosition);
		}

		else if (/*get_component("position")->get_position().x*/ currentBallPosition.x >= -1.0f)
		{
			mVelocity.x = -mVelocity.x;

			//engine::math::vector4 tempPosition = get_component("position")->get_position();
		currentBallPosition.x = 1.0f;

			//get_component("position")->set_position(tempPosition);
		}

		if (/*get_component("position")->get_position().y*/ currentBallPosition.y <= 1.0f)
		{
			mVelocity.y = -mVelocity.y;

			//engine::math::vector4 tempPosition = get_component("position")->get_position();
			currentBallPosition.y = 0.0f;

			//get_component("position")->set_position(tempPosition);
		}
	}

	return currentBallPosition;
}
