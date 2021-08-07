#include <glad.h>

#include <opengl/texture/TwoDTexture.h>
#include <opengl/factory/TwoDTextureGraphicComponentFactory.h>

#include <lesson/LearnOpenGLLesson.h>

namespace lesson {
	constexpr auto WIDTH = 800;
	constexpr auto HEIGHT = 600;

	const std::string WINDOW_NAME = "Learn OpenGL";
	const std::string TEXTURE_0_FILENAME = "res/textures/herb-potato-chip.jpg";
	const std::string TEXTURE_1_FILENAME = "res/textures/potato-chip-ridges.jpg";

	LearnOpenGLLesson::LearnOpenGLLesson() : OpenGLLesson(WINDOW_NAME, WIDTH, HEIGHT) {
		renderEngine = std::make_unique<opengl::RenderEngine>(windowName, width, height);
	}

	int LearnOpenGLLesson::run() {
		std::vector<float> vertices = {
			// x ,  y  ,  z  ,  r   ,  g   ,  b   ,  s  , t
			-0.4f, 0.4f, 0.0f, 0.90f, 0.22f, 0.21f, 0.3f, 0.7f,
			0.0f, 0.75f, 0.0f, 0.98f, 0.55f, 0.0f, 0.5f, 0.875f,
			0.4f, 0.4f, 0.0f, 0.99f, 0.85f, 0.21f, 0.7f, 0.7f,
			0.4f, -0.4f, 0.0f, 0.26f, 0.63f, 0.28f, 0.7f, 0.3f,
			0.0f, -0.75f, 0.0f,  0.12f, 0.53f, 0.89f, 0.5f, 0.125f,
			-0.4f, -0.4f, 0.0f, 0.37f, 0.21f, 0.69f, 0.3f, 0.3f,
		};

		std::vector<unsigned int> indices = {
			0, 1, 2,
			2, 3, 0,
			0, 3, 5,
			5, 4, 3
		};

		auto texture0 = opengl::texture::TwoDTexture(0, TEXTURE_0_FILENAME);
		auto texture1 = opengl::texture::TwoDTexture(1, TEXTURE_1_FILENAME);

		auto factory = opengl::factory::TwoDTextureGraphicComponentFactory();
		auto shaderProgram = factory.getShaderProgram();
		shaderProgram.setIntUniform(texture0.getTextureName(), texture0.getLocationId());
		shaderProgram.setIntUniform(texture1.getTextureName(), texture1.getLocationId());
		renderEngine->setShaderProgram(shaderProgram);

		auto vaoBuilder = factory.getVAOBuilder();
		vaoBuilder.setVertexBuffer(vertices);
		vaoBuilder.setIndexBuffer(indices);
		renderEngine->setVAO(vaoBuilder.build());

		renderEngine->run();

		return 0;
	}
}