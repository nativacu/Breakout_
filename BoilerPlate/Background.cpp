#include "Background.hpp"

background::background()
{
	mTexturePath = "assets/background.jpg";
}

void background::render()
{
	mRenderer.set_texture1(mRenderer.load_texture(mTexturePath, false));
	mRenderer.set_vertex_data(mVertices);
	mRenderer.set_texture_resolution();
	mRenderer.draw_polygon();
}



