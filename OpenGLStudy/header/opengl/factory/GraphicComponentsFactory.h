#pragma once

#include <opengl/vertex/VAOBuilder.h>
#include <opengl/shader/ShaderProgram.h>

namespace opengl {
	namespace factory {
		class GraphicComponentsFactory
		{
		public:
			virtual shader::ShaderProgram getShaderProgram() = 0;
			virtual vertex::VAOBuilder getVAOBuilder() = 0;
		};
	}
}