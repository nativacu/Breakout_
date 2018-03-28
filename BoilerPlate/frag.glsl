#version 330 core

out vec4 outColor;

in vec4 Color;
in vec2 Texcoord;

uniform sampler2D texture;

void main()
{
    outColor = texture(texture, Texcoord) * Color;
}