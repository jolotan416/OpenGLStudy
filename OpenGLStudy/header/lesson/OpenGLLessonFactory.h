#pragma once
#include <memory>

#include <lesson\OpenGLLesson.h>

namespace lesson {
	enum class OpenGLLessonType
	{
		LEGACY,
		MODERN_BASICS,
		LEARN_OPENGL
	};

	class OpenGLLessonFactory {
	public:
		std::unique_ptr<OpenGLLesson> create(OpenGLLessonType lessonType);
	};
}