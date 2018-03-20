#include "inputManager.hpp"

inputManager::inputManager()
{
	wKeyPressedStatus = false;
}

void inputManager::set_w_key_pressed_status(bool status)
{
	wKeyPressedStatus = status;
}

bool inputManager::get_w_key_status(void)
{
	return wKeyPressedStatus;
}
