#include <glm/gtc/matrix_transform.hpp>

#include <opengl/transforms/MatrixTransform.h>

namespace opengl {
	namespace transforms {
		void MatrixTransform::setTranslationTransform(TransformData transformData) {
			translationTransform = std::make_unique<TransformData>(transformData);
		}

		void MatrixTransform::setScalingTransform(TransformData transformData) {
			scalingTransform = std::make_unique<TransformData>(transformData);
		}

		void MatrixTransform::setRotationTransform(TransformData transformData) {
			rotationTransform = std::make_unique<TransformData>(transformData);
		}

		glm::mat4 MatrixTransform::buildTransformationMatrix(double time) {
			if (translationTransform) {
				transformationMatrix = glm::translate(transformationMatrix,
					glm::vec3(translationTransform->transformX(time),
						translationTransform->transformY(time),
						translationTransform->transformZ(time)));
			}

			if (scalingTransform) {
				transformationMatrix = glm::scale(transformationMatrix,
					glm::vec3(scalingTransform->transformX(time),
						scalingTransform->transformY(time),
						scalingTransform->transformZ(time)));
			}

			// TODO: Check how to use quarternions instead of Euler angles for rotation
			if (rotationTransform) {
				transformationMatrix = glm::rotate(transformationMatrix,
					rotationTransform->transformX(time),
					glm::vec3(1.0f, 0.0f, 0.0f));
				transformationMatrix = glm::rotate(transformationMatrix,
					rotationTransform->transformY(time),
					glm::vec3(0.0f, 1.0f, 0.0f));
				transformationMatrix = glm::rotate(transformationMatrix,
					rotationTransform->transformZ(time),
					glm::vec3(0.0f, 0.0f, 1.0f));
			}

			return transformationMatrix;
		}
	}
}