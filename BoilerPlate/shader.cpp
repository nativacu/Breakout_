#include "shader.hpp"

shader::shader()
{
}

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
		display_error_message(shader.first, "28", "Impossible to open file. Are you in the right directory? Don't forget to read the FAQ!\n", "Wrong File Path");
		getchar();
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

int shader::display_error_message(std::string fileName, std::string fileLine, std::string errorMessage, std::string rawErrorMessage)
{

	std::string complete_message = "File Name: " + fileName + "\nFile Line: " + fileLine + "\n" + errorMessage
		+ "\nUsing OpenGL 3.30 and GLSL 330 core";

	#ifdef _WIN32
	#include <Windows.h>
	
	LPCSTR display_message = complete_message.c_str();
	int msgboxID = MessageBoxA(
		NULL,
		display_message,
		rawErrorMessage.c_str(),
		MB_ICONWARNING | MB_OK
	);

	#elif defined __unix__ || defined _APPLE_

	std::cerr << complete_message;

	#endif
	return msgboxID;
}