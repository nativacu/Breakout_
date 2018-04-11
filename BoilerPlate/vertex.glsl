#version 330 core

// Input vertex data (attributes)
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aTexcoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;


// Output vertex data
out vec4 Color;
out vec2 Texcoord;

void main() {
	gl_Position = projection * view * model * vec4(aPos, 1.0f);
	//gl_Position = vec4(aPos, 1.0f);
	Color = aColor;
	Texcoord = aTexcoord;
}