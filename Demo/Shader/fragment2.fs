#version 330 core

in vec3 color;
in vec2 TexCoord;

// texture sampler
uniform sampler2D texture1;
out vec4 FragColor;

void main()
{
    FragColor = vec4(color, 1.0);
    //FragColor = texture(texture1, TexCoord);
}