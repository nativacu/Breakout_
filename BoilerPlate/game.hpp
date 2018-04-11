#pragma once
#ifndef _GAME_HPP
#define _GAME_HPP_

#include "renderer.hpp"
#include "inputManager.hpp"
#include "ball.hpp"
#include "block.hpp"
#include "paddle.hpp"
#include "gameLevelManager.hpp"
#include <vector>

namespace game
{
	class game
	{
		public:
			//CTOR
			game();
			game(int, int);
			void execute(void);
			void update(void);
			void render(void);
			void clean_up();
			void respond_to_input();
			void set_input(char pInput);
		private:
			engine::renderer::renderer	mRenderer;
			int mWidth;
			int mHeight;
			std::vector<block> mBlocks;
			GLuint mCurrentTexture;
			game::ball mBall;
			game::paddle mPaddle;
			game::gameLevelManager mLevelManager;
			engine::utilities::inputManager mInputManager;
	};
}

#endif // !_GAME_HPP

