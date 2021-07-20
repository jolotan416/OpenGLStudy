#include <iostream>

#include <glad.h>

#include <utilities/FileParser.h>

#include <opengl/shader/Shader.h>

namespace opengl {
	namespace shader {
		Shader::Shader(int shaderType, std::string filename) {
			auto fileParser = utilities::FileParser(filename);
			auto shaderString = fileParser.parseFile();
			auto shaderCString = shaderString.c_str();

			id = glCreateShader(shaderType);
			glShaderSource(id, 1, &(shaderCString), nullptr);
			glCompileShader(id);

			int compilationSuccess;
			glGetShaderiv(id, GL_COMPILE_STATUS, &compilationSuccess);
			if (!compilationSuccess) {
				char compileErrorLogs[MAX_SHADER_ERROR_CHAR];
				glGetShaderInfoLog(id, MAX_SHADER_ERROR_CHAR, nullptr, compileErrorLogs);
				std::cout << "Compile Error!! (" << shaderType << ") " << std::endl << std::endl << compileErrorLogs;

				id = INVALID_SHADER_ID;
			}
		}

		Shader::~Shader() {
			/*if (id != INVALID_SHADER_ID) {
				glDeleteShader(id);
			}*/
		}

		int Shader::getId() {
			return id;
		}
	}
}