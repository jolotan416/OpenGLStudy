#include <iostream>

#include <glad.h>

#include <opengl/RenderEngine.h>

namespace opengl {
	RenderEngine::RenderEngine(std::string windowName, int width, int height)
	{
		if (!glfwInit()) return;

		window = glfwCreateWindow(width, height, windowName.c_str() , nullptr, nullptr);
		if (!window)
		{
			glfwTerminate();

			return;
		}

		glfwMakeContextCurrent(window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cout << "Failed to initialize GLAD" << std::endl;

			return;
		}

		glViewport(0, 0, width, height);
		glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {
			std::cout << "Viewport adjusted with width: " << width << " and height: " << height << std::endl;
			glViewport(0, 0, width, height);
		});
	}

	RenderEngine::~RenderEngine()
	{
		glfwTerminate();
	}

	void RenderEngine::setVAO(std::unique_ptr<vertex::VAO> vao)
	{
		this->vao = std::move(vao);
	}

	void RenderEngine::setShaderProgram(shader::ShaderProgram program)
	{
		shaderProgram = std::make_unique<shader::ShaderProgram>(program);
	}

	void RenderEngine::setMatrixTransform(std::unique_ptr<transforms::MatrixTransform> transform)
	{
		matrixTransform = std::move(transform);
	}

	void RenderEngine::processInputs() {
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, true);
		}
	}

	void RenderEngine::run()
	{
		while (!glfwWindowShouldClose(window)) {
			processInputs();

			glClearColor(0.13f, 0.13f, 0.13f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			if (!vao) continue;

			if (matrixTransform) {
				shaderProgram->setTransform(
					matrixTransform->buildTransformationMatrix(glfwGetTime()));
			}
			glDrawElements(GL_TRIANGLES, vao->getNumberOfIndices(), GL_UNSIGNED_INT, 0);

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}
}