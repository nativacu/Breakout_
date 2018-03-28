#include "game.hpp"

game::game::game()
{
}

game::game::game(int width, int height)
{
	mWidth = width;
	mHeight = height;
	mRenderer = engine::renderer::renderer(mWidth, mHeight);
}

void game::game::execute(void)
{
	mRenderer.get_program_ID();
	Texture1 = mRenderer.load_texture("Assets/ball.png");
	mRenderer.set_vertex_data();
	mRenderer.set_texture_resolution();
}

void game::game::render(void)
{
	mRenderer.set_texture1(Texture1);
	mRenderer.get_program_ID();
	mRenderer.draw_polygon();
}

void game::game::clean_up()
{
	mRenderer.clean_up();
}
