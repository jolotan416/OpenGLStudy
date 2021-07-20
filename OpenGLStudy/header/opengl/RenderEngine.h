#pragma once

#include <glfw3.h>

#include <opengl/vertex/VAO.h>
#include <opengl/shader/ShaderProgram.h>

namespace opengl {
	class RenderEngine
	{
	public:
		RenderEngine(std::string, int, int);
		RenderEngine(RenderEngine&) = default;
		RenderEngine(RenderEngine&&) = default;

		RenderEngine& operator=(RenderEngine&) = default;
		RenderEngine& operator=(RenderEngine&&) = default;

		~RenderEngine();

		void setVAO(std::unique_ptr<vertex::VAO>);
		void setShaderProgram(shader::ShaderProgram);
		void run();

	private:
		void processInputs();

		std::unique_ptr<vertex::VAO> vao;
		std::unique_ptr<shader::ShaderProgram> shaderProgram;
		
		GLFWwindow* window;
	};
}