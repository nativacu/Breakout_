#include "renderer.hpp"

renderer::renderer()
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

	shaderUtility = shader(shaderInputList);

	usingWireFrameView = false;
}

void renderer::get_program_ID()
{
	ProgramID = shaderUtility.execute();
}

void renderer::draw_polygon()
{
	if (usingWireFrameView)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glUseProgram(ProgramID);
	glBindVertexArray(VertexArrayObject);
	glDrawArrays(GL_TRIANGLES, 0, 6); //limit vector buffering
}

void renderer::clean_up()
{
	glDeleteBuffers(1, &VertexBufferObject);
	glDeleteVertexArrays(1, &VertexArrayObject);
}

void renderer::set_vertex_data()
{
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	//float vertices[] = {
	//	-0.5f, -0.5f, 0.0f, // left  
	//	0.5f, -0.5f, 0.0f, // right 
	//	0.0f,  0.5f, 0.0f  // top   
	//};
	float vertices[] = {
		// first triangle
		0.5f,  0.5f, 0.0f,  // top right
		0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f,  0.5f, 0.0f, // top left 
		// second triangle
		0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f, // bottom left
		-0.5f,  0.5f, 0.0f  // top left
	};

	glGenVertexArrays(1, &VertexArrayObject);
	glGenBuffers(1, &VertexBufferObject);
	// bind the Vertex Array Object first, 
	// then bind and set vertex buffer(s), 
	// and then configure vertex attributes(s).
	glBindVertexArray(VertexArrayObject);

	glBindBuffer(GL_ARRAY_BUFFER, VertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		3 * sizeof(float),  // stride
		(void*)0            // array buffer offset
	);
	glEnableVertexAttribArray(0);

	// note that this is allowed, 
	// the call to glVertexAttribPointer registered VBO as the vertex attribute's bound 
	//vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);
}

void renderer::toggle_wire_frame_view(bool status)
{
	usingWireFrameView = status;
}
