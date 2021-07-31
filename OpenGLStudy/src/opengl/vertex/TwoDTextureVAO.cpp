#include <glad.h>

#include <opengl/vertex/TwoDTextureVAO.h>

namespace opengl {
	namespace vertex {
		TwoDTextureVAO::TwoDTextureVAO() : VAO() {}

		TwoDTextureVAO::~TwoDTextureVAO() {
			glDisableVertexAttribArray(POSITION_ATTRIB_LOCATION);
			glDisableVertexAttribArray(COLOR_ATTRIB_LOCATION);
			glDisableVertexAttribArray(TEXTURE_ATTRIB_LOCATION);
		}

		void TwoDTextureVAO::bindVertexAttributes() {
			glVertexAttribPointer(POSITION_ATTRIB_LOCATION, POSITION_ATTRIB_SIZE,
				GL_FLOAT, false, STRIDE, reinterpret_cast<void*>(POSITION_ATTRIB_OFFSET));
			glVertexAttribPointer(COLOR_ATTRIB_LOCATION, COLOR_ATTRIB_SIZE,
				GL_FLOAT, false, STRIDE, reinterpret_cast<void*>(COLOR_ATTRIB_OFFSET));
			glVertexAttribPointer(TEXTURE_ATTRIB_LOCATION, TEXTURE_ATTRIB_SIZE,
				GL_FLOAT, false, STRIDE, reinterpret_cast<void*>(TEXTURE_ATTRIB_OFFSET));
			glEnableVertexAttribArray(POSITION_ATTRIB_LOCATION);
			glEnableVertexAttribArray(COLOR_ATTRIB_LOCATION);
			glEnableVertexAttribArray(TEXTURE_ATTRIB_LOCATION);
		}
	}
}