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

	mBall.get_model_matrix()->translate_matrix(engine::math::vector4(0.0f, -0.9f, 0.0f, 0.0f));
	mBall.get_model_matrix()->rotate_using_radians(0.0f);
	mBall.get_model_matrix()->scale_matrix(1.0f, 1.0f, 1.0f);
}

void game::game::execute(void)
{
	
}

void game::game::update(void)
{
	respond_to_input();
}

void game::game::render(void)
{
	glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT );

	mRenderer.get_program_ID();
	//for (int i = 0; i < mBlocks.size(); i++) {
	//	mCurrentTexture = mRenderer.load_texture(mBlocks[i].get_texture_path(), mBlocks[i].get_alpha_status());
	//	mRenderer.set_vertex_data(mBlocks[i].get_vertices(),);
	//	mRenderer.set_texture_resolution();
	//	mRenderer.set_texture1(mCurrentTexture);
	//	mRenderer.draw_polygon();
	//}

	mCurrentTexture = mRenderer.load_texture(mBall.get_texture_path(), mBall.get_alpha_status());
	mRenderer.set_vertex_data(mBall.get_vertices(), mBall.get_model_matrix());
	mRenderer.set_texture_resolution();
	mRenderer.set_texture1(mCurrentTexture);
	mRenderer.draw_polygon();

	mBall.render();
	for (int i = 0; i < mBlocks.size(); i++) {
		mBlocks[i].render();
	}
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
