#include "block.hpp"

game::block::block()
{
	mTexturePath = "Assets/block.png";
	mIsUsingAlpha = false;
}

float* game::block::get_vertices() 
{
	return mVertices;
}