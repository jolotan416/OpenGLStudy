#pragma once

#include <memory>

#include <opengl/vertex/VBO.h>
#include <opengl/vertex/EBO.h>

namespace opengl {
	namespace vertex {
		class VAO {
		public:
			VAO();
			VAO(VAO&) = default;
			VAO(VAO&&) = default;
			
			VAO& operator=(VAO&) = default;
			VAO& operator=(VAO&&) = default;

			~VAO();

			virtual void bindVertexAttributes() = 0;
			void setVBO(std::unique_ptr<VBO>);
			void setEBO(std::unique_ptr<EBO>);
			int getNumberOfIndices();

		private:
			unsigned int id;
			std::unique_ptr<VBO> vbo;
			std::unique_ptr<EBO> ebo;
		};
	}
}