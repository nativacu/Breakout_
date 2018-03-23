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

	shaderUtility = engine::shaders::shader(shaderInputList);

	usingWireFrameView = false;

	//Added this

	mScreenHeight = height;
	mScreenWidth = width;
}

void engine::renderer::renderer::get_program_ID()
{
	ProgramID = shaderUtility.execute();
}

void engine::renderer::renderer::draw_polygon()
{
	int indices[] = {0, 1, 2, 1, 3, 2};
	if (usingWireFrameView)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glBindVertexArray(VertexArrayObject);
	glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, (void*)0); //limit vector buffering
}

void engine::renderer::renderer::clean_up()
{
	glDeleteBuffers(1, &VertexBufferObject);
	glDeleteVertexArrays(1, &VertexArrayObject);
	glDeleteVertexArrays(1, &ElementsBufferObject);
}

//Pretty much changed all this to make sure the thing interpreted the new vertices array and stuff
void engine::renderer::renderer::set_vertex_data()
{
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	//float vertices[] = {
	//	-0.5f, -0.5f, 0.0f, // left  
	//	0.5f, -0.5f, 0.0f, // right 
	//	0.0f,  0.5f, 0.0f  // top   
	//};
	/*float vertices[] = {
		// first triangle
		0.5f,  0.5f, 0.0f,  // top right
		0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f,  0.5f, 0.0f, // top left 
		// second triangle
		-0.5f, -0.5f, 0.0f, // bottom left
	};*/

	float vertices[] = {
		// positions          // colors           // texture coords
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
		-0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
	};

	unsigned int indices[] = {  // note that we start from 0!
		0, 1, 3,  // first Triangle
		1, 2, 3   // second Triangle
	};

	glGenVertexArrays(1, &VertexArrayObject);
	glGenBuffers(1, &VertexBufferObject);
	glGenBuffers(1, &ElementsBufferObject);

	glBindVertexArray(VertexArrayObject);

	glBindBuffer(GL_ARRAY_BUFFER, VertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ElementsBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// vertex position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// texture coord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}

void engine::renderer::renderer::toggle_wire_frame_view(bool status)
{
	usingWireFrameView = status;
}

//And this
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
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
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

void engine::renderer::renderer::set_texture_resolution(void)
{
	glUseProgram(ProgramID);

	// Remember this needs to be set after the program is activated
	glUniform1i(glGetUniformLocation(ProgramID, "texture1"), 0);

	float resolution[] = { static_cast<float>(mScreenWidth), static_cast<float>(mScreenWidth) };
	glUniform2fv(glGetUniformLocation(ProgramID, "resolution"), 1, resolution);
}
