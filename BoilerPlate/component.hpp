#pragma once
#ifndef _COMPONENT_HPP_
#define _COMPONENT_HPP_

#include <string>

//
#include "IUpdate.hpp"

namespace engine
{
	namespace core
	{
		class gameObject;
		class component : iUpdate
		{
		public:
			// PUBLIC FUNCTIONS
			explicit component(const std::string& name);
			~component();
			void update(double deltaTime) override;

			// GETTER FUNCTIONS
			void set_owner(gameObject* owner) { mOwner = owner; }
			gameObject* get_owner() const { return mOwner; }
			std::string get_name() const { return mName; }
		protected:
			// MEMBERS
			gameObject*	mOwner;
			std::string	mName;
		};
	}
}
#endif // !_COMPONENT_HPP_