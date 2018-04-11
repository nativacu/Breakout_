#include "gameLevelManager.hpp"
#include "vector2.hpp"
#include "vector3.hpp"
#include "block.hpp"
#include <fstream>
#include <sstream>


game::gameLevelManager::gameLevelManager()
{

}

std::vector<game::block> game::gameLevelManager::get_blocks()
{
	return mBlocks;
}

void game::gameLevelManager::load(const char * pFile, int pLevelWidth, int pLevelHeight)
{
	this->mBlocks.clear();

	// Load from file
	int tileCode;
	gameLevelManager level;
	std::string line;
	std::ifstream fstream(pFile);
	std::vector<std::vector<int>> pTileData;
	if (fstream)
	{
		while (std::getline(fstream, line)) // Read each line from level file
		{
			std::istringstream sstream(line);
			std::vector<int> row;
			while (sstream >> tileCode) // Read each word seperated by spaces
				row.push_back(tileCode);
			pTileData.push_back(row);
		}

		if (pTileData.size() > 0) {
			this->init(pTileData, pLevelWidth, pLevelHeight);
		}
	}
}

void game::gameLevelManager::init(std::vector<std::vector<int>> pTileData, int pLevelWidth, int pLevelHeight)
{
	// Calculate dimensions
	int height = pTileData.size();
	int width = pTileData[0].size(); // Note we can index vector at [0] since this function is only called if height > 0
	float unitWidth = pLevelWidth / static_cast<float>(width), unitHeight = pLevelHeight / height;
	// Initialize level tiles based on pTileData		
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			// Check block type from level data (2D level array)
			if (pTileData[y][x] == 1) // Solid
			{
				engine::math::vector2 position(unitWidth * x, unitHeight * y);
				engine::math::vector2 size(unitWidth, unitHeight);

				//create the object
				game::block block = game::block();
				mBlocks.push_back(block);
			}
			else if (pTileData[y][x] > 1)	// Non-solid; now determine its color based on level data
			{
				engine::math::vector3 color(1.0f);
				if (pTileData[y][x] == 2) {
					game::block block = game::block();
					//game::block* block = new game::block(engine::math::vector3(0.2f, 0.6f, 1.0f));
					block.get_model_matrix()->translate_matrix(engine::math::vector4((unitWidth * x) - 1.365, (unitHeight * -y) + 0.8, 0.0f, 0.0f));
					this->mBlocks.push_back(block);
					color = engine::math::vector3(0.2f, 0.6f, 1.0f);
				}

				else if (pTileData[y][x] == 3) {
					game::block block = game::block();
					//game::block* block = new game::block(engine::math::vector3(0.2f, 0.6f, 1.0f));
					block.get_model_matrix()->translate_matrix(engine::math::vector4((unitWidth * x) - 1.365, (unitHeight * -y) + 0.8, 0.0f, 0.0f));
					this->mBlocks.push_back(block);
					color = engine::math::vector3(0.2f, 0.6f, 1.0f);
				}

				else if (pTileData[y][x] == 4) {
					game::block block = game::block();
					//game::block* block = new game::block(engine::math::vector3(0.2f, 0.6f, 1.0f));
					block.get_model_matrix()->translate_matrix(engine::math::vector4((unitWidth * x) - 1.365, (unitHeight * -y) + 0.8, 0.0f, 0.0f));
					this->mBlocks.push_back(block);
					color = engine::math::vector3(0.2f, 0.6f, 1.0f);
				}

				else if (pTileData[y][x] == 5) {
					game::block block = game::block();
					//game::block* block = new game::block(engine::math::vector3(0.2f, 0.6f, 1.0f));
					block.get_model_matrix()->translate_matrix(engine::math::vector4((unitWidth * x) - 1.365, (unitHeight * -y) + 0.8, 0.0f, 0.0f));
					this->mBlocks.push_back(block);
					color = engine::math::vector3(0.2f, 0.6f, 1.0f);
				}

			}
		}
	}
}


