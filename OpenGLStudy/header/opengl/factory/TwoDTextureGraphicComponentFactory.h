#pragma once

#include <opengl/factory/GraphicComponentsFactory.h>

namespace opengl {
	namespace factory {
		class TwoDTextureGraphicComponentFactory : public GraphicComponentsFactory {
		public:
			shader::ShaderProgram getShaderProgram() override;
			vertex::VAOBuilder getVAOBuilder() override;

		private:
			static const std::string VERTEX_SHADER_FILENAME;
			static const std::string FRAGMENT_SHADER_FILENAME;
		};
	}
}