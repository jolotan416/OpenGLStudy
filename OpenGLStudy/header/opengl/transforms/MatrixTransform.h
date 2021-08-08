#pragma once
#define GLM_FORCE_CXX14

#include <memory>

#include <glm/glm.hpp>

#include <opengl/transforms/TransformData.h>

namespace opengl {
	namespace transforms {
		class MatrixTransform {
		public:
			void setTranslationTransform(TransformData);
			void setScalingTransform(TransformData);
			void setRotationTransform(TransformData);
			glm::mat4 buildTransformationMatrix(double);

		private:
			glm::mat4 transformationMatrix = glm::mat4(1.0f);
			std::unique_ptr<TransformData> translationTransform = nullptr;
			std::unique_ptr<TransformData> scalingTransform = nullptr;
			std::unique_ptr<TransformData> rotationTransform = nullptr;
		};
	}
}