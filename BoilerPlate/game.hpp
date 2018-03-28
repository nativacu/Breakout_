#pragma once
#ifndef _GAME_HPP
#define _GAME_HPP_

#include "renderer.hpp"
#include "ball.hpp"
#include "block.hpp"
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
		private:
			engine::renderer::renderer	mRenderer;
			int mWidth;
			int mHeight;
			std::vector<block> mBlocks;
			GLuint mCurrentTexture;
			game::ball mBall;
	};
}

#endif // !_GAME_HPP

