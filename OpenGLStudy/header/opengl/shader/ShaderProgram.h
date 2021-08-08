#pragma once

#include <string>

#include <glm/glm.hpp>

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

			void setTexture(int);
			void setTransform(glm::mat4);

		private:
			static const std::string TEXTURE_UNIFORM_NAME;
			static const std::string TRANSFORM_UNIFORM_NAME;

			int id;
		};
	}
}