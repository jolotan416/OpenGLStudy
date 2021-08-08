#pragma once

namespace opengl {
	namespace transforms {
		struct TransformData {
		public:
			float transformX(float x) {
				return transformCoordinate(x, xCoefficient, xConstant);
			}

			float transformY(float y) {
				return transformCoordinate(y, yCoefficient, yConstant);
			}

			float transformZ(float z) {
				return transformCoordinate(z, zCoefficient, zConstant);
			}

			float xCoefficient;
			float xConstant;
			float yCoefficient;
			float yConstant;
			float zCoefficient;
			float zConstant;
		private:
			// TODO: Check how to make more than a linear transformation
			float transformCoordinate(float coordinate, float coefficient,
				float constant) {
				return coefficient * coordinate + constant;
			}
		};
	}
}