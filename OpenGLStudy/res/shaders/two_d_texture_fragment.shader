#version 330 core

in vec4 outputColor;
in vec2 outputTextureCoordinates;

out vec4 fragColor;

uniform sampler2D texture0;
uniform sampler2D texture1;

void main() {
	fragColor = mix(texture(texture0, outputTextureCoordinates),
		texture(texture1, outputTextureCoordinates), 0.4);
}