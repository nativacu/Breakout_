#pragma once
#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

namespace engine
{
	namespace utilities 
	{
		class inputManager
		{
		public:
			// CTOR
			inputManager();

			// Public functions
			void set_w_key_pressed_status(bool);
			void set_a_key_pressed_status(bool);
			void set_d_key_pressed_status(bool);
			void set_space_key_pressed_status(bool);
			bool get_w_key_status(void);
			bool get_a_key_status(void);
			bool get_d_key_status(void);
			bool get_space_key_status(void);

		private:
			// Private members
			bool wKeyPressedStatus;
			bool aKeyPressedStatus;
			bool dKeyPressedStatus;
			bool spaceKeyPressedStatus;
		};
	}
}

#endif // !INPUT_MANAGER_H