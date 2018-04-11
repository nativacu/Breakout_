#pragma once
#ifndef _COLLISION_COMPONENT_HPP_
#define _COLLISION_COMPONENT_HPP_

#include "component.hpp"
#include "ball.hpp"
#include "gameObject.hpp"
#include "vector2.hpp"

namespace engine
{
	namespace components
	{
		class collisionComponent : public engine::core::component
		{
		public:
			collisionComponent();
			bool CheckCollision(game::ball &one, engine::core::gameObject &two) // AABB - Circle collision
			{
				// Get center point circle first 
				engine::math::vector2 center(one.get_component("position")->get_position + one.get_radius());
				// Calculate AABB info (center, half-extents)
				engine::math::vector2 aabb_half_extents(two.get_size() / 2, two.get_size() / 2);
				engine::math::vector2 aabb_center(
					two.get_component("position")->get_position().x + aabb_half_extents.x,
					two.get_component("position")->get_position().y + aabb_half_extents.y
				);
				// Get difference vector between both centers
				engine::math::vector2 difference = center - aabb_center;
				// Add clamped value to AABB_center and we get the value of box closest to circle
				engine::math::vector2 closest = aabb_center;
				// Retrieve vector between center circle and closest point AABB and check if length <= radius
				engine::math::vector2 difference = closest - center;
				return difference.get_length() < one.get_radius();
			}

			bool CheckCollision(engine::core::gameObject &one, engine::core::gameObject &two) // AABB - AABB collision
			{
				// Collision x-axis?
				bool collisionX = one.get_component("position")->get_position().x + one.get_size() >= two.get_component("position")->get_position().x &&
					two.get_component("position")->get_position().x + two.get_size() >= one.get_component("position")->get_position().x;
				// Collision y-axis?
				bool collisionY = one.get_component("position")->get_position().y + one.get_size >= two.get_component("position")->get_position().y &&
					two.get_component("position")->get_position().y + two.get_size() >= one.get_component("position")->get_position().y;
				// Collision only if on both axes
				return collisionX && collisionY;
			}
		};
	}
}

#endif // !_COLLISION_COMPONENT_HPP_

