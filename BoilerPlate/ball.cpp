#include "ball.hpp"

game::ball::ball()
{
	mTexturePath = "assets/ball.png";
}

float * game::ball::get_vertices()
{
	return mVertices;
}

std::string game::ball::getTexturePath()
{
	return mTexturePath;
}
