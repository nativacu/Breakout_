#version 330 core

// Input vertex data (attributes)
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aTexcoord;

// Output vertex data
out vec4 Color;
out vec2 Texcoord;

void main() {
	gl_Position = vec4(aPos,1.0f);
	Color = aColor;
	Texcoord = aTexcoord;
}