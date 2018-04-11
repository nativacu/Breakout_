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

	mBlocks[0].get_model_matrix()->translate_matrix(engine::math::vector4(0.0f, 0.3f, 0.0f, 0.0f));
	mBlocks[0].get_model_matrix()->rotate_using_radians(0.0f);
	mBlocks[0].get_model_matrix()->scale_matrix(1.0f, 1.0f, 1.0f);

	mBall.get_model_matrix()->translate_matrix(engine::math::vector4(0.0f, -0.7f, 0.0f, 0.0f));
	mBall.get_model_matrix()->rotate_using_radians(0.0f);
	mBall.get_model_matrix()->scale_matrix(1.0f, 1.0f, 1.0f);

	mPaddle.get_model_matrix()->translate_matrix(engine::math::vector4(0.0f, -0.9f, 0.0f, 0.0f));
	mPaddle.get_model_matrix()->rotate_using_radians(0.0f);
	mPaddle.get_model_matrix()->scale_matrix(1.0f, 1.0f, 1.0f);
}

void game::game::execute(void)
{
	mRenderer.get_program_ID();
}

void game::game::update(void)
{
	respond_to_input();
}

void game::game::render(void)
{
	glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT );

	for (int i = 0; i < mBlocks.size(); i++) {
		mRenderer.render_object(mBlocks[i]);
	}

	mRenderer.render_object(mBall);
	mRenderer.render_object(mPaddle);
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
