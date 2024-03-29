#include <opengl/vertex/VAOBuilder.h>
#include <opengl/vertex/PositionColorVAO.h>
#include <opengl/vertex/TwoDTextureVAO.h>

namespace opengl {
	namespace vertex {
		VAOBuilder::VAOBuilder(VAOType type) {
			switch (type)
			{
			case opengl::vertex::VAOType::POSITION_COLOR:
				vao = std::make_unique<PositionColorVAO>();

				break;
			case opengl::vertex::VAOType::TWO_D_TEXTURE:
				vao = std::make_unique<TwoDTextureVAO>();

				break;
			default:
				break;
			}
		}

		void VAOBuilder::setVertexBuffer(std::vector<float> vertexBuffer) {
			vao->setVBO(std::make_unique<VBO>(vertexBuffer));
		}

		void VAOBuilder::setIndexBuffer(std::vector<unsigned int> indexBuffer) {
			vao->setEBO(std::make_unique<EBO>(indexBuffer));
		}

		std::unique_ptr<VAO> VAOBuilder::build() {
			vao->bindVertexAttributes();

			return std::move(vao);
		}
	}
}