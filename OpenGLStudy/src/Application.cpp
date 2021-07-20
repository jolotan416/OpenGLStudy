#include <iostream>

#include <lesson\OpenGLLessonFactory.h>

using namespace lesson;

int main(void)
{
	OpenGLLessonFactory factory = OpenGLLessonFactory();
	std::unique_ptr<OpenGLLesson> lesson = factory.create(OpenGLLessonType::LEARN_OPENGL);
	
	return lesson->run();
}