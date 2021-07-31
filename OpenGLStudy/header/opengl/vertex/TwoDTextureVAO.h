#pragma once

#include <opengl/vertex/VAO.h>

namespace opengl {
	namespace vertex {
		class TwoDTextureVAO : public VAO
		{
		public:
			TwoDTextureVAO();
			~TwoDTextureVAO();

			TwoDTextureVAO(TwoDTextureVAO&) = default;
			TwoDTextureVAO(TwoDTextureVAO&&) = default;

			TwoDTextureVAO& operator=(TwoDTextureVAO&) = default;
			TwoDTextureVAO& operator=(TwoDTextureVAO&&) = default;

			void bindVertexAttributes() override;

		private:
			static constexpr int POSITION_ATTRIB_LOCATION = 0;
			static constexpr int COLOR_ATTRIB_LOCATION = 1;
			static constexpr int TEXTURE_ATTRIB_LOCATION = 2;

			static constexpr int POSITION_ATTRIB_SIZE = 3;
			static constexpr int COLOR_ATTRIB_SIZE = 3;
			static constexpr int TEXTURE_ATTRIB_SIZE = 2;
			static constexpr int STRIDE = (POSITION_ATTRIB_SIZE + COLOR_ATTRIB_SIZE + TEXTURE_ATTRIB_SIZE) * sizeof(float);

			static constexpr int POSITION_ATTRIB_OFFSET = 0;
			static constexpr int COLOR_ATTRIB_OFFSET = POSITION_ATTRIB_SIZE * sizeof(float);
			static constexpr int TEXTURE_ATTRIB_OFFSET = (POSITION_ATTRIB_SIZE + COLOR_ATTRIB_SIZE) * sizeof(float);
		};
	}
}