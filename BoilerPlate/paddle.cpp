#include "paddle.hpp"

game::paddle::paddle()
{
	mTexturePath = "assets/paddle.png";
	mIsUsingAlpha = true;
}

float * game::paddle::get_vertices()
{
	return mVertices;
}


