#include "gameObject.hpp"

// STL
#include <algorithm>

// 
#include "component.hpp"

namespace engine
{
	namespace core
	{
		gameObject::gameObject()
			: mParent(nullptr)
		{}

		gameObject::~gameObject()
		{
			// Delete all attached components
			//
			//while (!mComponents.empty()) delete mComponents.back(), mComponents.pop_back();

			// Delete all attached children
			//
			while (!mChildren.empty()) delete mChildren.back(), mChildren.pop_back();
		}

		void gameObject::attach_component(component* component)
		{
			component->set_owner(this);
			mComponents.push_back(component);
		}

		void gameObject::remove_component(component* component)
		{
			mComponents.erase(
				remove(mComponents.begin(), mComponents.end(), component), mComponents.end()
			);

			delete component;
		}

		void gameObject::add_child(gameObject* child)
		{
			// Set the child parent
			child->mParent = this;

			// 
			mChildren.push_back(child);
		}

		void gameObject::remove_child(gameObject* child)
		{
			mChildren.erase(
				remove(mChildren.begin(), mChildren.end(), child), mChildren.end()
			);

			delete child;
		}

		void gameObject::update(double deltaTime)
		{
			// Update components
			//
			std::vector< component* >::iterator comp = mComponents.begin();
			for (; comp != mComponents.end(); ++comp)
			{
				(*comp)->update(deltaTime);
			}

			// Update children
			//
			std::vector< gameObject* >::iterator child = mChildren.begin();
			for (; child != mChildren.end(); ++child)
			{
				(*child)->update(deltaTime);
			}

			// Base class function call
			//
			iUpdate::update(deltaTime);
		}

		void gameObject::render()
		{
			{
				// Render children
				//
				std::vector< gameObject* >::iterator child = mChildren.begin();
				for (; child != mChildren.end(); ++child)
				{
					(*child)->render();
				}
			}
		}
		bool gameObject::get_alpha_status(void)
		{
			return mIsUsingAlpha;
		}
		
		const char * gameObject::get_texture_path()
		{
			return mTexturePath;
		}

		float * gameObject::get_vertices()
		{
			return nullptr;
		}

		float gameObject::get_size()
		{
			return mSize;
		}

		component * gameObject::get_component(std::string pComponentName)
		{
			for (int i = 0; i < mComponents.size(); i++)
			{
				if (mComponents[i]->get_name() == pComponentName)
				{
					return mComponents[i];
				}
			}

			return NULL;
		}

		engine::math::matrix4* gameObject::get_model_matrix()
		{
			return &mModelMatrix;
		}
	}
}