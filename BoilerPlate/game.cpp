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

void game::game::update(void)
{
	respond_to_input();
}

void game::game::render(void)
{
	mRenderer.set_texture1(mCurrentTexture);
	mRenderer.draw_polygon();
}

void game::game::clean_up()
{
	mRenderer.clean_up();
}

void game::game::respond_to_input()
{
	if (mInputManager.get_w_key_status())	{
		mRenderer.toggle_wire_frame_view(true);
	}

	if (!mInputManager.get_w_key_status()){
		mRenderer.toggle_wire_frame_view(false);
	}
}

void game::game::set_input(char pInput)
{
	if (pInput == 'w') {
		mInputManager.set_w_key_pressed_status(true);
	}
	else{
		mInputManager.set_w_key_pressed_status(false);
	}
}