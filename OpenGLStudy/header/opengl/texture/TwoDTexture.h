#pragma once

#include <string>
#include <memory>

#include <utilities/ImageLoader.h>

namespace opengl {
	namespace texture {
		class TwoDTexture
		{
		public:
			TwoDTexture(int, std::string);
			~TwoDTexture();

			TwoDTexture(TwoDTexture&) = default;
			TwoDTexture(TwoDTexture&&) = default;

			TwoDTexture& operator=(TwoDTexture&) = default;
			TwoDTexture& operator=(TwoDTexture&&) = default;

			int getLocationId();

		private:
			unsigned int id;
			int locationId;
			std::unique_ptr<utilities::ImageLoader> imageLoader;
		};
	}
}