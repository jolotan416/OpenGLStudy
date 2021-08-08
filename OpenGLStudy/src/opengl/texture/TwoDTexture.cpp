#include <iostream>

#include <glad.h>

#include <opengl/texture/TwoDTexture.h>

namespace opengl {
	namespace texture {
		TwoDTexture::TwoDTexture(int locId, std::string filename) {
			locationId = locId;
			imageLoader = std::make_unique<utilities::ImageLoader>(filename);

			glActiveTexture(GL_TEXTURE0 + locId);
			glGenTextures(1, &id);
			glBindTexture(GL_TEXTURE_2D, id);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageLoader->getWidth(),
				imageLoader->getHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, imageLoader->getImageData());
			glGenerateMipmap(GL_TEXTURE_2D);
		}

		TwoDTexture::~TwoDTexture() {
			glDeleteTextures(1, &id);
		}

		int TwoDTexture::getLocationId() {
			return locationId;
		}
	}
}