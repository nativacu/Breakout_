#version 330 core

in vec3 Color;
in vec2 Texcoord;

out vec4 outColor;

uniform sampler2D texture1;

void main()
{
    outColor = texture(texture1, Texcoord) * vec4(Color, 1.0);
}