#pragma once

#include <string>

namespace utilities {
	class ImageLoader {
	public:
		ImageLoader(std::string);
		~ImageLoader();

		ImageLoader(ImageLoader&) = default;
		ImageLoader(ImageLoader&&) = default;

		ImageLoader& operator=(ImageLoader&) = default;
		ImageLoader& operator=(ImageLoader&&) = default;

		int getWidth() const;
		int getHeight() const;
		unsigned char* getImageData() const;

	private:
		int width;
		int height;
		unsigned char* imageData;
	};
}