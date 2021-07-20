#include <iostream>

#include <lesson\LegacyOpenGLLesson.h>

namespace lesson {
	constexpr auto WIDTH = 640;
	constexpr auto HEIGHT = 480;

	const std::string WINDOW_NAME = "Legacy OpenGL";

	LegacyOpenGLLesson::LegacyOpenGLLesson(): OpenGLLesson(WINDOW_NAME, WIDTH, HEIGHT) {}

	int LegacyOpenGLLesson::run() {
		OpenGLLesson::run();

		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
		{
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);

			/* [JOLO NOTES] Legacy OpenGL to test debugging by creating a triangle */
			glBegin(GL_TRIANGLES);
			glVertex2f(-0.5f, -0.5f);
			glVertex2f(0.0f, 0.5f);
			glVertex2f(0.5f, -0.5f);
			glEnd();

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		}

		glfwTerminate();
		return 0;
	}
}