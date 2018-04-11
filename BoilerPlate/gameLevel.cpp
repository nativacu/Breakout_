#include "gameLevel.hpp"

game::gameLevel::gameLevel()
{

}

void game::gameLevel::load(const char * pFile, float pLevelWidth, float pLevelHeight)
{
	// Load from file
	GLuint tileCode;
	game::gameLevel level;
	std::string line;
	std::ifstream fstream(pFile);
	std::vector<std::vector<GLuint>> tileData;
	if (fstream)
	{
		while (std::getline(fstream, line))
		{
			std::istringstream sstream(line);
			std::vector<GLuint> row;

			while (sstream >> tileCode)
				row.push_back(tileCode);
			tileData.push_back(row);
		}
		if (tileData.size() > 0)
			init(tileData, pLevelWidth, pLevelHeight);
	}
}

void game::gameLevel::init(std::vector<std::vector<GLuint>> tileData, float levelWidth, float levelHeight)
{
	int height = tileData.size();
	int width = tileData[0].size();
	float unitWidth = levelWidth / static_cast<float>(width);
	float unitHeight = levelHeight / height;

	// Initialize level tiles based on tileData		
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			// Check block type from level data (2D level array)
			if (tileData[y][x] == 1)
			{
				//objects::solid_block* newBlock = new objects::solid_block();

				//newBlock->translate(engine::math::vector_4((unitWidth * x) - 1.365, (unitHeight * -y) + 0.8, 0.0f, 0.0f));

				//this->mBlocks.push_back(newBlock);
			}
			else if (tileData[y][x] > 1)
			{
				if (tileData[y][x] == 2)
				{
					block* newBlock = new block(engine::math::vector4(0.2f, 0.6f, 1.0f, 1.0f));
					newBlock->get_component("position")->set_position(engine::math::vector4((unitWidth * x) - 1.365, (unitHeight * -y) + 0.8, 0.0f, 0.0f));
					this->mBlocks.push_back(newBlock);
				}
				else if (tileData[y][x] == 3)
				{
					game::block* newBlock = new game::block(engine::math::vector4(0.0f, 0.7f, 0.0f, 1.0f));
					newBlock->get_component("position")->set_position(engine::math::vector4((unitWidth * x) - 1.365, (unitHeight * -y) + 0.8, 0.0f, 0.0f));
					mBlocks.push_back(newBlock);
				}
				else if (tileData[y][x] == 4)
				{
					game::block* newBlock = new game::block(engine::math::vector4(0.8f, 0.8f, 0.4f, 1.0f));
					newBlock->get_component("position")->set_position(engine::math::vector4((unitWidth * x) - 1.365, (unitHeight * -y) + 0.8, 0.0f, 0.0f));
					mBlocks.push_back(newBlock);
				}
				else if (tileData[y][x] == 5)
				{
					game::block* newBlock = new game::block(engine::math::vector4(1.0f, 0.5f, 0.0f, 1.0f));
					newBlock->get_component("position")->set_position(engine::math::vector4((unitWidth * x) - 1.365, (unitHeight * -y) + 0.8, 0.0f, 0.0f));
					mBlocks.push_back(newBlock);
				}

			}

		}
	}
}


