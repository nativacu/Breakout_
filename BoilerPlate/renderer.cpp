#include "renderer.hpp"

engine::renderer::renderer::renderer()
{
}

engine::renderer::renderer::renderer(int width, int height)
{
	// MANAGE SHADER INPUT PAIR LIST (ADITIONAL SHADER PATHS AND TYPES SHOULD BE ADDED HERE
	std::vector <std::pair <std::string, GLenum>> shaderInputList;
	std::pair<std::string, GLenum> firstShaderEntry;
	std::pair<std::string, GLenum> secondShaderEntry;

	firstShaderEntry.first = "vertex.glsl";
	firstShaderEntry.second = GL_VERTEX_SHADER;

	secondShaderEntry.first = "frag.glsl";
	secondShaderEntry.second = GL_FRAGMENT_SHADER;

	shaderInputList.push_back(firstShaderEntry);
	shaderInputList.push_back(secondShaderEntry);

	mShaderUtility = engine::utilities::shaderUtility(shaderInputList);

	mUsingWireFrameView = false;

	mScreenHeight = height;
	mScreenWidth = width;
}

void engine::renderer::renderer::get_program_ID()
{
	mProgramID = mShaderUtility.execute();
}

void engine::renderer::renderer::draw_polygon()
{
	int indices[] = {0, 1, 2, 1, 3, 2};
	if (mUsingWireFrameView)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glBindVertexArray(mVertexArrayObject);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mElementsBufferObject);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture1);

	glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, (void*)0); //limit vector buffering
}

void engine::renderer::renderer::clean_up()
{
	glDeleteBuffers(1, &mVertexBufferObject);
	glDeleteVertexArrays(1, &mVertexArrayObject);
	glDeleteVertexArrays(1, &mElementsBufferObject);
}

void engine::renderer::renderer::set_vertex_data()
{
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	float vertices[] = {
		// positions          // colors					// texture coords
		0.05f,  0.05f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
		0.05f, -0.05f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,	 1.0f, 0.0f,   // bottom right
		-0.05f, -0.05f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,	 0.0f, 0.0f,   // bottom left
		-0.05f,  0.05f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 1.0f    // top left 
	};

	unsigned int indices[] = {
		0, 1, 3,  // first Triangle
		1, 2, 3   // second Triangle
	};

	glGenVertexArrays(1, &mVertexArrayObject);
	glGenBuffers(1, &mVertexBufferObject);
	glGenBuffers(1, &mElementsBufferObject);

	glBindVertexArray(mVertexArrayObject);

	glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mElementsBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// vertex position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// color attribute
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// texture coord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(7 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}

void engine::renderer::renderer::toggle_wire_frame_view(bool status)
{
	mUsingWireFrameView = status;
}

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

GLuint engine::renderer::renderer::load_texture(const char * texture_path)
{
	// https://open.gl/textures
	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);

	// Load the texture
	unsigned char *data = stbi_load(texture_path, &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
		return -1;
	}
	stbi_image_free(data);

	return texture;
}

void engine::renderer::renderer::set_texture1(GLuint a)
{
	texture1 = a;
}

void engine::renderer::renderer::set_texture_resolution(void)
{
	glUseProgram(mProgramID);
	glUniform1i(glGetUniformLocation(mProgramID, "texture1"), 0);
}
