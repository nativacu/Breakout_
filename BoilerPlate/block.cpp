#include "block.hpp"
#include "positionComponent.hpp"

game::block::block()
{
	mTexturePath = "assets/block.png";
	mIsUsingAlpha = false;

	engine::components::positionComponent *positionComponent =
		new engine::components::positionComponent("position", engine::math::vector4(-0.5f, 0.3f, 0.0f, 0.0f));

	attach_component(positionComponent);
}

game::block::block(engine::math::vector4 color)
{
	mTexturePath = "assets/block.png";
	mIsUsingAlpha = false;

	engine::components::positionComponent *positionComponent =
		new engine::components::positionComponent("position", engine::math::vector4(0.0f, 0.3f, 0.0f, 0.0f));

	attach_component(positionComponent);
}

float* game::block::get_vertices() 
{
	return mVertices;
}