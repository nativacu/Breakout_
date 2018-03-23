#version 330 core

out vec4 outColor;

in vec3 Color;
in vec2 Texcoord;

uniform sampler2D texture;

void main()
{
    outColor = texture(texture, Texcoord) * vec4(1.0, 1.0, 1.0, 1.0);
}