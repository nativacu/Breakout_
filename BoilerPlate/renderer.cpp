#include "renderer.hpp"
#include "matrix4.hpp"

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
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mElementsBufferObject);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mTexture);

	glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, (void*)0); //limit vector buffering
}

void engine::renderer::renderer::clean_up()
{
	glDeleteBuffers(1, &mVertexBufferObject);
	glDeleteVertexArrays(1, &mVertexArrayObject);
	glDeleteVertexArrays(1, &mElementsBufferObject);
}

void engine::renderer::renderer::render_object(engine::core::gameObject & pObject)
{

	set_texture1(load_texture(pObject.get_texture_path(),pObject.get_alpha_status()));
	set_vertex_data(pObject.get_vertices(),pObject.get_model_matrix());
	set_texture_resolution();
	draw_polygon();
}

void engine::renderer::renderer::set_vertex_data(float* pVertices, engine::math::matrix4* pModelMatrix)
{
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	float vertices[36];

	for (int i = 0; i < 36; i++)
	{
		vertices[i] = pVertices[i];
		
	}
	
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

	// create transformations
	engine::math::matrix4 model;
	engine::math::matrix4 view;
	engine::math::matrix4 projection;

	view.translate_matrix(engine::math::vector4(0.0f, 0.0f, -3.0f, 1.0f));
	view.rotate_using_radians(0.0f);

	projection.make_perspective_matrix(35.0f, 0.1f, 100.0f, static_cast<float> (1136 / 640));

	GLuint modelLoc = glGetUniformLocation(mProgramID, "model");
	GLuint viewLoc = glGetUniformLocation(mProgramID, "view");
	GLuint projectionLoc = glGetUniformLocation(mProgramID, "projection");

	float modelMatrix[16];
	float viewMatrix[16];
	float projectionMatrix[16];

	pModelMatrix->set_matrix(modelMatrix);
	view.set_matrix(viewMatrix);
	projection.set_matrix(projectionMatrix);

	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, modelMatrix);
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, viewMatrix);
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, projectionMatrix);
}

void engine::renderer::renderer::toggle_wire_frame_view(bool status)
{
	mUsingWireFrameView = status;
}

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

GLuint engine::renderer::renderer::load_texture(const char * texture_path, bool isUsingAlpha)
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
		if(!isUsingAlpha)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		else
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
	mTexture = a;
}

void engine::renderer::renderer::set_texture_resolution(void)
{
	glUseProgram(mProgramID);
	glUniform1i(glGetUniformLocation(mProgramID, "mTexture"), 0);
}
