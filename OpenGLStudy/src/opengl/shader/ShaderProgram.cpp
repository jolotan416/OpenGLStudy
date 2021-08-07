#include <iostream>

#include <glad.h>

#include <opengl/shader/Shader.h>

#include <opengl/shader/ShaderProgram.h>

namespace opengl {
	namespace shader {
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

		void ShaderProgram::setIntUniform(const std::string& variableName, int value) {
			auto variableLocation = glGetUniformLocation(id, variableName.c_str());
			glUniform1i(variableLocation, value);
		}
	}
}