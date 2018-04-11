#include "ball.hpp"

game::ball::ball()
{
	mTexturePath = "assets/ball.png";
	mIsUsingAlpha = true;
}

float * game::ball::get_vertices()
{
	return mVertices;
}