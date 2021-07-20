#include <iostream>

#include <lesson\OpenGLLesson.h>

namespace lesson {
	OpenGLLesson::OpenGLLesson(std::string windowName, int width, int height) {
		this->windowName = windowName;
		this->width = width;
		this->height = height;
	}

	int OpenGLLesson::run() {
		/* Initialize GLFW library */
		if (!glfwInit()) return -1;

		/* Create window... */
		window = glfwCreateWindow(width, height, windowName.c_str() , nullptr, nullptr);
		if (!window)
		{
			glfwTerminate();
			return -1;
		}

		/* ...and make it the main context of the current thread */
		glfwMakeContextCurrent(window);

		return 0;
	}
}