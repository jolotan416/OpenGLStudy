#pragma once

#include <memory>

#include <opengl/vertex/VAOType.h>
#include <opengl/vertex/VAO.h>

namespace opengl {
	namespace vertex {
		class VAOBuilder {
		public:
			VAOBuilder(VAOType);

			void setVertexBuffer(std::vector<float>);
			void setIndexBuffer(std::vector<unsigned int>);
			std::unique_ptr<VAO> build();

		private:
			std::unique_ptr<VAO> vao;
		};
	}
}