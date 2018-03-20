#pragma once
#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

class inputManager
{
public:
	// CTOR
	inputManager();

	// Public functions
	void set_w_key_pressed_status(bool);
	bool get_w_key_status(void);
	

private:
	// Private members
	bool wKeyPressedStatus;
};

#endif // !INPUT_MANAGER_H