#version 330 core

in vec4 outputColor;
out vec4 fragColor;

void main() {
	fragColor = outputColor;
}