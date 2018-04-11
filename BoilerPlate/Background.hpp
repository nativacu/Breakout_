#pragma once
#include "renderer.hpp"
#include "matrix4.hpp"
class background 
{
public:
	background();
	void render();
private:
	float mVertices[36]{
		// positions          // colors					// texture coords
		2.0f,  2.0f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
		2.0f, -2.0f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,	1.0f, 0.0f,   // bottom right
		-2.0f, -2.0f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,	 0.0f, 0.0f,   // bottom left
		-2.0f,  2.0f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 1.0f    // top left 
	};
	const char* mTexturePath;
	engine::renderer::renderer mRenderer;
};

