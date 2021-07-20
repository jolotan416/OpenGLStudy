#include <iostream>
#include <glew.h>

#include <utilities/FileParser.h>

#include <lesson/ModernOpenGLBasicLesson.h>

namespace lesson {
	constexpr auto WIDTH = 640;
	constexpr auto HEIGHT = 480;

	const std::string WINDOW_NAME = "Modern OpenGL";
	const std::string VERTEX_SHADER_FILENAME = "res/shaders/position_color_vertex.shader";
	const std::string FRAGMENT_SHADER_FILENAME = "res/shaders/position_color_fragment.shader";

	ModernOpenGLBasicLesson::ModernOpenGLBasicLesson() : OpenGLLesson(WINDOW_NAME, WIDTH, HEIGHT) {}

	int ModernOpenGLBasicLesson::run() {
		OpenGLLesson::run();

		/* [JOLO NOTES] Call glewInit once window's current context is ready */
		if (GLEW_OK != glewInit()) {
			std::cout << "Glew init not OK!" << std::endl;
		}

		std::cout << glGetString(GL_VERSION) << std::endl;

		float positions[] = {
			-0.5f, -0.5f,
			0.0f, 0.5f,
			0.5f, 0.0f
		};
		unsigned int bufferId;
		size_t numberOfBuffers = 1;
		glGenBuffers(numberOfBuffers, &bufferId);
		/* [JOLO NOTES] create an array buffer */
		glBindBuffer(GL_ARRAY_BUFFER, bufferId);
		/* [JOLO NOTES] Tell OpenGL what to do with our buffer and the data for it 
			but this is just a bytestream for OpenGL right now */
		glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		/* [JOLO NOTES] Tells OpenGL what the layout of the buffer is
			and what it contains (instead of just a bystream) */
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);

		/* [JOLO NOTES] Reading vertex and fragment shaders from file and creating a program out of it */
		auto shaderProgramId = createShaderProgram();
		glUseProgram(shaderProgramId);

		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
		{
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);

			/* [JOLO NOTES] tell OpenGL what is inside the buffer and then draw */
			/* [JOLO NOTES] Some GPUs can give default shaders that can generate the correct thing hehe */
			glDrawArrays(GL_TRIANGLES, 0, 3);

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		}

		//glDeleteProgram(shaderProgramId);
		glDisableVertexAttribArray(0);
		glfwTerminate();
		return 0;
	}

	/* [JOLO NOTES] Utility function created to avoid boilerplate code for compiling shaders */
	unsigned int ModernOpenGLBasicLesson::compileShader( unsigned int shaderType, const std::string& shaderCode) {
		auto shaderId = glCreateShader(shaderType);
		const char* sourceCodeCString = shaderCode.c_str();
		glShaderSource(shaderId, 1, &sourceCodeCString, nullptr);
		glCompileShader(shaderId);

		/* [JOLO NOTES] Error handling to check issues when compiling shaders */
		int shaderCompilationResult;
		glGetShaderiv(shaderId, GL_COMPILE_STATUS, &shaderCompilationResult);
		if (shaderCompilationResult == GL_FALSE) {
			int logLength;
			glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &logLength);
			auto logMessage = static_cast<char*>(alloca(sizeof(char) * logLength));
			glGetShaderInfoLog(shaderId, logLength, &logLength, logMessage);
			std::cout << "ERROR: Failed to compile " << (shaderType == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader" << std::endl;
			std::cout << logMessage << std::endl;
			glDeleteShader(shaderId);

			return 0;
		}

		return shaderId;
	}

	/* [JOLO NOTES] Creates shader program and links shaders after compiling them */
	unsigned int ModernOpenGLBasicLesson::createShaderProgram() {
		auto vertexShaderCode = utilities::FileParser(VERTEX_SHADER_FILENAME).parseFile();
		auto fragmentShaderCode = utilities::FileParser(FRAGMENT_SHADER_FILENAME).parseFile();

		auto programId = glCreateProgram();
		auto vertexShaderId = compileShader(GL_VERTEX_SHADER, vertexShaderCode);
		auto fragmentShaderId = compileShader(GL_FRAGMENT_SHADER, fragmentShaderCode);

		glAttachShader(programId, vertexShaderId);
		glAttachShader(programId, fragmentShaderId);
		glLinkProgram(programId);
		glValidateProgram(programId);

		/* [JOLO NOTES] Deletes compiled shaders (see glDetachShader though) */
		glDeleteShader(vertexShaderId);
		glDeleteShader(fragmentShaderId);

		return programId;
	}
}