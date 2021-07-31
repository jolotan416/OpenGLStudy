#version 330 core

in vec4 outputColor;
in vec2 outputTextureCoordinates;

out vec4 fragColor;

uniform sampler2D sampleTexture;

void main() {
	fragColor = texture(sampleTexture, outputTextureCoordinates);
}