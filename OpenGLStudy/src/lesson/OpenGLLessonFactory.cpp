#include <iostream>

#include <lesson/OpenGLLessonFactory.h>
#include <lesson/LegacyOpenGLLesson.h>
#include <lesson/ModernOpenGLBasicLesson.h>
#include <lesson/LearnOpenGLLesson.h>

namespace lesson {
	std::unique_ptr<OpenGLLesson> OpenGLLessonFactory::create(OpenGLLessonType lessonType) {
		std::cout << "Creating an OpenGL Lesson of type ";

		switch (lessonType) {
		case OpenGLLessonType::LEGACY:
			std::cout << " Legacy" << std::endl;
			return std::make_unique<LegacyOpenGLLesson>();
		case OpenGLLessonType::MODERN_BASICS:
			std::cout << " Modern Basics" << std::endl;
			return std::make_unique<ModernOpenGLBasicLesson>();
		case OpenGLLessonType::LEARN_OPENGL:
			std::cout << "Learn OpenGL" << std::endl;
			return std::make_unique<LearnOpenGLLesson>();
		default:
			std::cout << " Default" << std::endl;
			return std::make_unique<ModernOpenGLBasicLesson>(); // Always default to the latest lesson
		}
	}
}