#pragma once

#include <string>
#include <memory>

#include <utilities/ImageLoader.h>

namespace opengl {
	namespace texture {
		class TwoDTexture
		{
		public:
			TwoDTexture(std::string);
			~TwoDTexture();

			TwoDTexture(TwoDTexture&) = default;
			TwoDTexture(TwoDTexture&&) = default;

			TwoDTexture& operator=(TwoDTexture&) = default;
			TwoDTexture& operator=(TwoDTexture&&) = default;

		private:
			unsigned int id;
			std::unique_ptr<utilities::ImageLoader> imageLoader;
		};
	}
}