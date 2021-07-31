#include <opengl/factory/TwoDTextureGraphicComponentFactory.h>

namespace opengl {
	namespace factory {
		const std::string TwoDTextureGraphicComponentFactory::VERTEX_SHADER_FILENAME = "res/shaders/two_d_texture_vertex.shader";
		const std::string TwoDTextureGraphicComponentFactory::FRAGMENT_SHADER_FILENAME = "res/shaders/two_d_texture_fragment.shader";

		shader::ShaderProgram TwoDTextureGraphicComponentFactory::getShaderProgram() {
			return shader::ShaderProgram(VERTEX_SHADER_FILENAME, FRAGMENT_SHADER_FILENAME);
		}

		vertex::VAOBuilder TwoDTextureGraphicComponentFactory::getVAOBuilder() {
			return vertex::VAOBuilder(vertex::VAOType::TWO_D_TEXTURE);
		}
	}
}