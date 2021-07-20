#include <glad.h>

#include <opengl/factory/PositionColorGraphicComponentsFactory.h>

#include <lesson/LearnOpenGLLesson.h>

namespace lesson {
	constexpr auto WIDTH = 800;
	constexpr auto HEIGHT = 600;

	const std::string WINDOW_NAME = "Learn OpenGL";

	LearnOpenGLLesson::LearnOpenGLLesson() : OpenGLLesson(WINDOW_NAME, WIDTH, HEIGHT) {
		renderEngine = std::make_unique<opengl::RenderEngine>(windowName, width, height);
	}

	int LearnOpenGLLesson::run() {
		std::vector<float> vertices = {
			-0.4f, 0.4f, 0.0f, 0.90f, 0.22f, 0.21f,
			0.0f, 0.75f, 0.0f, 0.98f, 0.55f, 0.0f,
			0.4f, 0.4f, 0.0f, 0.99f, 0.85f, 0.21f,
			0.4f, -0.4f, 0.0f, 0.26f, 0.63f, 0.28f,
			0.0f, -0.75f, 0.0f,  0.12f, 0.53f, 0.89f,
			-0.4f, -0.4f, 0.0f, 0.37f, 0.21f, 0.69f
		};

		std::vector<unsigned int> indices = {
			0, 1, 2,
			2, 3, 0,
			0, 3, 5,
			5, 4, 3
		};

		auto factory = opengl::factory::PositionColorGraphicComponentsFactory();
		renderEngine->setShaderProgram(factory.getShaderProgram());

		auto vaoBuilder = factory.getVAOBuilder();
		vaoBuilder.setVertexBuffer(vertices);
		vaoBuilder.setIndexBuffer(indices);
		renderEngine->setVAO(vaoBuilder.build());

		renderEngine->run();

		return 0;
	}
}