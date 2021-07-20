#include <iostream>

#include <glad.h>

#include <opengl/vertex/EBO.h>

namespace opengl {
	namespace vertex {
		EBO::EBO(std::vector<unsigned int> indexBuffer) {
			std::cout << "Generating EBO..." << std::endl;

			buffer = indexBuffer;
			glGenBuffers(1, &id);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, buffer.size() * sizeof(unsigned int),
				buffer.data(), GL_STATIC_DRAW);
		}

		EBO::~EBO() {
			std::cout << "EBO dead" << std::endl;
			glDeleteBuffers(1, &id);
		}

		int EBO::getNumberOfIndices() {
			return buffer.size();
		}
	}
}