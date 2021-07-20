#include <iostream>

#include <glad.h>

#include <opengl/vertex/VBO.h>

namespace opengl {
	namespace vertex {
		VBO::VBO(std::vector<float> vertexBuffer) {
			std::cout << "Generating VBO..." << std::endl;

			buffer = vertexBuffer;
			glGenBuffers(1, &id);
			glBindBuffer(GL_ARRAY_BUFFER, id);
			glBufferData(GL_ARRAY_BUFFER, buffer.size() * sizeof(float), 
				buffer.data(), GL_STATIC_DRAW);
		}

		VBO::~VBO() {
			std::cout << "VBO dead" << std::endl;
			glDeleteBuffers(1, &id);
		}
	}
}