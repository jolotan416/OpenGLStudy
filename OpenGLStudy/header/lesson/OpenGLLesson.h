#pragma once
#include<glfw3.h>

namespace lesson {
	class OpenGLLesson {
	public:
		virtual int run();

	protected:
		OpenGLLesson(std::string, int width, int height);

		GLFWwindow* window;
		std::string windowName;
		int width;
		int height;
	};
}