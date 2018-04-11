#pragma once
#ifndef _GAME_LEVEL_MANAGER_HPP
#define _GAME_LEVEL_MANAGER_HPP_

#include "block.hpp"
namespace game {
	class gameLevelManager
	{
	public:
		gameLevelManager();

		std::vector<block> get_blocks();
		void load(const char *pFile, int pLevelWidth, int pLevelHeight);

	private:
		std::vector<block>mBlocks;
		void init(std::vector<std::vector<int>> pTileData, int pLevelWidth, int pLevelHeight);
	};
}
#endif