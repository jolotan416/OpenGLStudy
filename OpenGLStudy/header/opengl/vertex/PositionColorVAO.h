#pragma once

#include <opengl/vertex/VAO.h>

namespace opengl {
	namespace vertex {
		class PositionColorVAO : public VAO
		{
		public:
			PositionColorVAO();
			PositionColorVAO(PositionColorVAO&) = default;
			PositionColorVAO(PositionColorVAO&&) = default;

			PositionColorVAO& operator=(PositionColorVAO&) = default;
			PositionColorVAO& operator=(PositionColorVAO&&) = default;

			~PositionColorVAO();

			void bindVertexAttributes() override;

		private:
			static constexpr int POSITION_ATTRIB_LOCATION = 0;
			static constexpr int COLOR_ATTRIB_LOCATION = 1;

			static constexpr int POSITION_ATTRIB_SIZE = 3;
			static constexpr int COLOR_ATTRIB_SIZE = 3;
			static constexpr int STRIDE = (POSITION_ATTRIB_SIZE + COLOR_ATTRIB_SIZE) * sizeof(float);

			static constexpr int POSITION_ATTRIB_OFFSET = 0;
			static constexpr int COLOR_ATTRIB_OFFSET = POSITION_ATTRIB_SIZE * sizeof(float);
		};
	}
}