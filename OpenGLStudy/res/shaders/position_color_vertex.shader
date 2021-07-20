#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 inputColor;

out vec4 outputColor;

void main() {
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
	outputColor = vec4(inputColor, 1.0);
}