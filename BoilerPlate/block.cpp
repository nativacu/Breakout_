#include "block.hpp"

game::block::block()
{
	mTexturePath = "assets/block.png";
	mIsUsingAlpha = false;
}

float* game::block::get_vertices() 
{
	return mVertices;
}