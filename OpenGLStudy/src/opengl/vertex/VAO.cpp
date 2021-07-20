#include <iostream>

#include <glad.h>

#include <opengl/vertex/VAO.h>

namespace opengl {
	namespace vertex {
		VAO::VAO() {
			std::cout << "Generating vertex array..." << std::endl;
			glGenVertexArrays(1, &id);
			glBindVertexArray(id);
		}

		VAO::~VAO() {
			std::cout << "VAO dead" << std::endl;
			glDeleteVertexArrays(1, &id);
		}

		void VAO::setVBO(std::unique_ptr<VBO> vbo) {
			this->vbo = std::move(vbo);
		}

		void VAO::setEBO(std::unique_ptr<EBO> ebo) {
			this->ebo = std::move(ebo);
		}

		int VAO::getNumberOfIndices() {
			return ebo->getNumberOfIndices();
		}
	}
}