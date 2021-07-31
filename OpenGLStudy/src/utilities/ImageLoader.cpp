#define STB_IMAGE_IMPLEMENTATION

#include <stb_image.h>

#include <utilities/ImageLoader.h>

namespace utilities {
	ImageLoader::ImageLoader(const std::string filename) {
		int bitComponentPerPixel;

		stbi_set_flip_vertically_on_load(true);
		imageData = stbi_load(filename.c_str(), &width, &height, &bitComponentPerPixel, 0);
	}

	ImageLoader::~ImageLoader() {
		stbi_image_free(imageData);
	}

	int ImageLoader::getWidth() const {
		return width;
	}

	int ImageLoader::getHeight() const {
		return height;
	}

	unsigned char* ImageLoader::getImageData() const {
		return imageData;
	}
}