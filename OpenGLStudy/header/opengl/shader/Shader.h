#pragma once

#define MAX_SHADER_ERROR_CHAR 512
#define INVALID_SHADER_ID -1

#include <string>

namespace opengl {
	namespace shader {
		class Shader
		{
		public:
			Shader(int, std::string);
			Shader(Shader&) = default;
			Shader(Shader&&) = default;

			Shader& operator=(Shader&) = default;
			Shader& operator=(Shader&&) = default;

			~Shader();

			int getId();

		private:
			int id;
		};
	}
}