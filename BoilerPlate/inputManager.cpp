#include "inputManager.hpp"

namespace engine
{
	namespace utilities 
	{
		inputManager::inputManager()
		{
			wKeyPressedStatus = false;
			aKeyPressedStatus = false;
			dKeyPressedStatus = false;
		}

		void inputManager::set_w_key_pressed_status(bool status)
		{
			wKeyPressedStatus = status;
		}

		void inputManager::set_a_key_pressed_status(bool status)
		{
			aKeyPressedStatus = status;
		}

		void inputManager::set_d_key_pressed_status(bool status)
		{
			dKeyPressedStatus = status;
		}

		bool inputManager::get_w_key_status(void)
		{
			return wKeyPressedStatus;
		}
		bool inputManager::get_a_key_status(void)
		{
			return aKeyPressedStatus;
		}
		bool inputManager::get_d_key_status(void)
		{
			return dKeyPressedStatus;
		}
	}
}
