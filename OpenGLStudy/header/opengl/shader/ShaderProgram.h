#pragma once

#include <string>

namespace opengl {
	namespace shader {
		class ShaderProgram
		{
		public:
			ShaderProgram(std::string, std::string);
			ShaderProgram(ShaderProgram&) = default;
			ShaderProgram(ShaderProgram&&) = default;

			ShaderProgram& operator=(ShaderProgram&) = default;
			ShaderProgram& operator=(ShaderProgram&&) = default;

			~ShaderProgram();

		private:
			int id;
		};
	}
}