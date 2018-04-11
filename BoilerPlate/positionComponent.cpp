#include "positionComponent.hpp"

engine::components::positionComponent::positionComponent(std::string pName, engine::math::vector4 pOriginalPosition)
{
	mName = pName;
	mOriginalPosition = pOriginalPosition;
	mCurrentPosition = pOriginalPosition;
}

engine::math::vector4 engine::components::positionComponent::get_position()
{
	return mCurrentPosition;
}

void engine::components::positionComponent::set_position(engine::math::vector4 newPosition)
{
	mCurrentPosition = newPosition;
}


