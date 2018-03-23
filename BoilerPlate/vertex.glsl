#version 330 core

// Input vertex data (attributes)
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

// Output vertex data
out vec3 ourColor;
out vec2 TexCoord;

void main() {
	ourColor = aColor;
	TexCoord = aTexCoord;
}