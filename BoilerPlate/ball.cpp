#include "ball.hpp"

game::ball::ball()
{
	mTexturePath = "Assets/ball.png";
	mIsUsingAlpha = true;
}

float * game::ball::get_vertices()
{
	return mVertices;
}