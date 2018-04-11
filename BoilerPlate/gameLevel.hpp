#pragma once
#ifndef _GAME_LEVEL_HPP_
#define _GAME_LEVEL_HPP_

#include <GL/glew.h>
#include "block.hpp"
#include <sstream>
#include <fstream>
#include <GL/glew.h>

namespace game
{
	class gameLevel
	{
	public:
		gameLevel();
		void load(const char *pFile, float pLevelWidth, float pLevelHeight);
		void init(std::vector<std::vector<GLuint>> tileData, float levelWidth, float levelHeight);

		std::vector<block*> mBlocks;
	};
}

#endif // !_GAME_LEVEL_HPP_

