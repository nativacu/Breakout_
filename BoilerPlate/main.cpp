#if _MSC_VER && _DEBUG
	#define _CRTDBG_MAP_ALLOC
	#include <crtdbg.h>
#endif

// C++ STL
#include <cassert>
#include <iostream>
#include <cstdlib>

// 
#include "App.hpp"

const int WIDTH = 1136;
const int HEIGHT = 640;

int main(int argc, char* argv[])
{
/*
#if _MSC_VER && _DEBUG
	// https://msdn.microsoft.com/en-us/library/x98tx3cf.aspx
	// This will help you detect leaks when using Visual C++
	// Uncomment this line to start getting reports!
	assert(_CrtCheckMemory());
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	// Create Game Object
	//
	Engine::App* app = new Engine::App("Boiler Plate!", WIDTH, HEIGHT);

	// Initialize game
	//
	if(!app->Init())
	{
		std::cout << "App Init error!\n";
		return -1;
	}

	// Execute game
	//
	app->Execute();

	// Delete game object
	//
	delete app;
	*/

	float entries[16] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	matrix4 matrix;
	matrix4 newMatrix = matrix4(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
	matrix4 lastMatrix = matrix4(entries);

	std::cout << matrix;
	std::cout << std::endl;

	std::cout << newMatrix;
	std::cout << std::endl;

	std::cout << lastMatrix;
	std::cout << std::endl;

	float* test;

	return 0;
}