#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 inputColor;
layout(location = 2) in vec2 inputTextureCoordinates;

out vec4 outputColor;
out vec2 outputTextureCoordinates;

void main() {
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
	outputColor = vec4(inputColor, 0.5);
	outputTextureCoordinates = inputTextureCoordinates;
}