#pragma once
#ifndef _GAMEOBJECT_HPP_
#define _GAMEOBJECT_HPP_

#include <vector>

//
#include "iUpdate.hpp"
#include "iRender.hpp"
#include "uniqueID.hpp"
#include "matrix4.hpp"

namespace engine
{
	namespace core
	{
		class component;
		class gameObject : public iUpdate, public iRender, public uniqueID
		{
		public:
			// CTOR
			gameObject();
			~gameObject();

			// PUBLIC FUNCTIONS
			void attach_component(component*);
			void remove_component(component*);
			void add_child(gameObject*);
			void remove_child(gameObject*);
			void update(double deltaTime) override;
			virtual void render() override;

			// GETTER FUNCTIONS
			bool get_alpha_status(void);
			const char* get_texture_path();
			std::vector<component*>get_components() const { return mComponents; }
			std::vector<gameObject*> get_children() const { return mChildren; }
			gameObject* get_parent() const { return mParent; }
			virtual float* get_vertices();

			component *get_component(std::string pComponentName);

			engine::math::matrix4* get_model_matrix();
		protected:
			// MEMBERS
			std::vector<component*>	mComponents;
			std::vector<gameObject*> mChildren;
			gameObject* mParent;
			const char* mTexturePath;
			bool mIsUsingAlpha;
			engine::math::matrix4 mModelMatrix;
			float mSize;
		};
	}
}

#endif // !_GAMEOBJECT_HPP_