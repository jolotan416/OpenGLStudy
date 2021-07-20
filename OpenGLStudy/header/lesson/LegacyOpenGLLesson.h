#pragma once
#include <lesson\OpenGLLesson.h>

/*
* This contains the following:
* 1. Lesson 2: Setting up OpenGL from The Cherno (https://www.youtube.com/watch?v=OR4fNpBjmq8&list=PLlrATfBNZ98foTJPJ_Ev03o2oq3-GGOS2&index=2)
*/
namespace lesson {
	class LegacyOpenGLLesson : public OpenGLLesson {
	public:
		LegacyOpenGLLesson();

		int run() override;
	};
}