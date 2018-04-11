#pragma once
#ifndef _POSITION_COMPONENT_HPP_
#define _POSITION_COMPONENT_HPP_

#include "component.hpp"

namespace engine
{
	namespace components
	{
		class positionComponent : public engine::core::component
		{
		public:
			positionComponent(std::string pName, engine::math::vector4 pOriginalPosition);
			engine::math::vector4 get_position() override;
			void set_position(engine::math::vector4) override;

		private:
			engine::math::vector4 mOriginalPosition;
			engine::math::vector4 mCurrentPosition;
			float mVelocity;
			int mSceneWidth;
		};
	}
}

#endif // !_POSITION_COMPONENT_HPP_

