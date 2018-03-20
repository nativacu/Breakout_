#include "shader.hpp"

shader::shader(std::vector<std::pair<std::string, GLenum>> inputList)
{
	shaderList = inputList;
}

GLuint shader::create_handle(std::pair<std::string, GLenum> shader)
{
	GLuint currentShaderID;
	currentShaderID = glCreateShader(shader.second);

	return currentShaderID;
}

std::string shader::read_code_from_file(std::pair<std::string, GLenum> shader)
{
	// Read the Vertex Shader code from the file
	std::string currentShaderCode;
	std::ifstream currentShaderStream(shader.first, std::ios::in);
	if (currentShaderStream.is_open()) {
		std::stringstream sstr;
		sstr << currentShaderStream.rdbuf();
		currentShaderCode = sstr.str();
		currentShaderStream.close();
	}
	else {
		printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", shader.first);
		getchar();
		// Behavior on failed attempt (message box perhaps?)
	}

	return currentShaderCode;
}

void shader::compile_shader(GLuint shaderHandler, std::string shaderCode, std::string filePath)
{
	printf("Compiling shader : %s\n", filePath);
	char const * shaderSourcePointer = shaderCode.c_str();
	glShaderSource(shaderHandler, 1, &shaderSourcePointer, NULL);
	glCompileShader(shaderHandler);

	// Check Vertex Shader
	glGetShaderiv(shaderHandler, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(shaderHandler, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(shaderHandler, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
		printf("%s\n", &VertexShaderErrorMessage[0]);
	}
}

void shader::link_program()
{
	printf("Linking program\n");
	ProgramID = glCreateProgram();
	for(int i = 0; i < shaderHandlerList.size(); i++)
	{ 
		// Attach shaders
		glAttachShader(ProgramID, shaderHandlerList[i]);
	}

	// Link the program
	glLinkProgram(ProgramID);

	// Check the program
	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
		glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
		printf("%s\n", &ProgramErrorMessage[0]);
	}
}

void shader::clean_up()
{
	for(int i = 0; i < shaderHandlerList.size(); i++)
	{ 
		glDetachShader(ProgramID, shaderHandlerList[i]);

		glDeleteShader(shaderHandlerList[i]);
	}
}

GLuint shader::execute()
{
	for (int i = 0; i < shaderList.size(); i++)
	{
		// Create handle
		GLuint handler = create_handle(shaderList[i]);

		// Read from file
		std::string shaderCode = read_code_from_file(shaderList[i]);

		// Compile
		compile_shader(handler, shaderCode, shaderList[i].first);

		shaderHandlerList.push_back(handler);
	}

	// Link program
	link_program();

	// Cleanup
	clean_up();

	return ProgramID;
}