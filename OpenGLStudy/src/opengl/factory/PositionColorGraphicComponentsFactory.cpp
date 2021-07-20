#include <opengl/vertex/VAOType.h>
#include <opengl/vertex/VAOBuilder.h>
#include <opengl/shader/ShaderProgram.h>

#include <opengl/factory/PositionColorGraphicComponentsFactory.h>

namespace opengl {
	namespace factory {
		const std::string PositionColorGraphicComponentsFactory::VERTEX_SHADER_FILENAME = "res/shaders/position_color_vertex.shader";
		const std::string PositionColorGraphicComponentsFactory::FRAGMENT_SHADER_FILENAME = "res/shaders/position_color_fragment.shader";

		shader::ShaderProgram PositionColorGraphicComponentsFactory::getShaderProgram() {
			return shader::ShaderProgram(VERTEX_SHADER_FILENAME, FRAGMENT_SHADER_FILENAME);
		}

		vertex::VAOBuilder PositionColorGraphicComponentsFactory::getVAOBuilder() {
			return vertex::VAOBuilder(vertex::VAOType::POSITION_COLOR);
		}
	}
}