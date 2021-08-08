#include <iostream>

#include <glad.h>
#include <glm/gtc/type_ptr.hpp>

#include <opengl/shader/Shader.h>

#include <opengl/shader/ShaderProgram.h>

namespace opengl {
	namespace shader {
		const std::string ShaderProgram::TEXTURE_UNIFORM_NAME = "texture";
		const std::string ShaderProgram::TRANSFORM_UNIFORM_NAME = "transform";

		ShaderProgram::ShaderProgram(std::string vertexShaderFilename,
			std::string fragmentShaderFilename) {
			auto vertexShader = Shader(GL_VERTEX_SHADER, vertexShaderFilename);
			auto fragmentShader = Shader(GL_FRAGMENT_SHADER, fragmentShaderFilename);

			id = glCreateProgram();
			glAttachShader(id, vertexShader.getId());
			glAttachShader(id, fragmentShader.getId());
			glLinkProgram(id);

			int linkingSuccess;
			glGetProgramiv(id, GL_LINK_STATUS, &linkingSuccess);
			if (!linkingSuccess) {
				char linkingErrorLogs[MAX_SHADER_ERROR_CHAR];
				glGetShaderInfoLog(id, MAX_SHADER_ERROR_CHAR, nullptr, linkingErrorLogs);
				std::cout << "Linking Error!!" << std::endl << std::endl << linkingErrorLogs;

				return;
			}

			glUseProgram(id);
		}

		ShaderProgram::~ShaderProgram() {
			if (id != INVALID_SHADER_ID) {
				glDeleteProgram(id);
			}
		}

		void ShaderProgram::setTexture(int textureLocationId) {
			auto variableLocation = glGetUniformLocation(id,
				(TEXTURE_UNIFORM_NAME + std::to_string(textureLocationId)).c_str());
			glUniform1i(variableLocation, textureLocationId);
		}

		void ShaderProgram::setTransform(glm::mat4 transform) {
			auto variableLocation = glGetUniformLocation(id, TRANSFORM_UNIFORM_NAME.c_str());
			glUniformMatrix4fv(variableLocation, 1, GL_FALSE, glm::value_ptr(transform));
		}
	}
}