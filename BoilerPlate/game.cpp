#include "game.hpp"

game::game::game()
{
}

game::game::game(int width, int height)
{
	mWidth = width;
	mHeight = height;
	mRenderer = engine::renderer::renderer(mWidth, mHeight);
	mBlocks.push_back(block());
}

void game::game::execute(void)
{
	mRenderer.get_program_ID();
	for (int i = 0; i < mBlocks.size(); i++) {
		mCurrentTexture = mRenderer.load_texture(mBlocks[i].get_texture_path(), mBlocks[i].get_alpha_status());
		mRenderer.set_vertex_data(mBlocks[i].get_vertices());
		mRenderer.set_texture_resolution();
	}

	mCurrentTexture = mRenderer.load_texture(mBall.get_texture_path(), mBall.get_alpha_status());
	mRenderer.set_vertex_data(mBall.get_vertices());
	mRenderer.set_texture_resolution();
}

void game::game::render(void)
{
	//mRenderer.set_texture1(mCurrentTexture);
	mRenderer.draw_polygon();
}

void game::game::clean_up()
{
	mRenderer.clean_up();
}
