#include "paddle.hpp"

game::paddle::paddle()
{
	mTexturePath = "assets/paddle.png";
	mIsUsingAlpha = true;
	mSize = 0.2f;

	engine::components::positionComponent *positionComponent =
		new engine::components::positionComponent("position", engine::math::vector4(0.0f, -0.9f, 0.0f, 0.0f));

	attach_component(positionComponent);
}

float * game::paddle::get_vertices()
{
	return mVertices;
}


