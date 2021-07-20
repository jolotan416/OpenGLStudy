#include <iostream>

#include <glad.h>

#include <opengl/vertex/PositionColorVAO.h>

namespace opengl {
	namespace vertex {
		PositionColorVAO::PositionColorVAO() : VAO() {}

		PositionColorVAO::~PositionColorVAO() {
			glDisableVertexAttribArray(POSITION_ATTRIB_LOCATION);
			glDisableVertexAttribArray(COLOR_ATTRIB_LOCATION);
		}

		void PositionColorVAO::bindVertexAttributes() {
			std::cout << "Binding vertex attributes..." << std::endl;
			glVertexAttribPointer(POSITION_ATTRIB_LOCATION, POSITION_ATTRIB_SIZE,
				GL_FLOAT, GL_FALSE, STRIDE, reinterpret_cast<void*>(POSITION_ATTRIB_OFFSET));
			glVertexAttribPointer(COLOR_ATTRIB_LOCATION, COLOR_ATTRIB_SIZE,
				GL_FLOAT, GL_FALSE, STRIDE, reinterpret_cast<void*>(COLOR_ATTRIB_OFFSET));
			glEnableVertexAttribArray(POSITION_ATTRIB_LOCATION);
			glEnableVertexAttribArray(COLOR_ATTRIB_LOCATION);
		}
	}
}