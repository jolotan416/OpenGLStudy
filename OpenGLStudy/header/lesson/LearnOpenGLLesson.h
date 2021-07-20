#pragma once

#include <opengl/RenderEngine.h>

#include <lesson/OpenGLLesson.h>

/*
Lesson containing learnings from the following reference: https://learnopengl.com/book/book_pdf.pdf
*/
namespace lesson {
	class LearnOpenGLLesson : public OpenGLLesson {
	public:
		LearnOpenGLLesson();

		int run() override;

	private:
		std::unique_ptr<opengl::RenderEngine> renderEngine;
	};
}