#include <fstream>
#include <GL/glew.h>
#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <vector>
#include <Windows.h>
#include <SDL2/SDL_opengl.h>

#pragma once
#ifndef _RESOURCE_MANAGER_HPP_
#define _RESOURCE_MANAGER_HPP_

namespace engine 
{
	namespace utilities
	{
		//Manages all thins related to sound, textures, and text renderization
		class resourceManager
		{
			// PUBLIC FUNCTIONS
			// TEXT MANAGING FUNCTIONS
			bool initialize_library();
			void clean_up_library();
			unsigned int power_two_floor(unsigned int);

			// AUDIO MANAGING FUNCTIONS

		};
	}	
}

#endif // !_RESOURCE_MANAGER_HPP_

