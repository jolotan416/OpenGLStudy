#pragma once

#include <lesson\OpenGLLesson.h>

/*
* This contains the following:
* 1. Lesson 3: Using Modern OpenGL (https://www.youtube.com/watch?v=H2E3yO0J7TM&list=PLlrATfBNZ98foTJPJ_Ev03o2oq3-GGOS2&index=3)
* 2. Lesson 4: Vertex Buffers and Drawing a Triangle (https://www.youtube.com/watch?v=0p9VxImr7Y0&list=PLlrATfBNZ98foTJPJ_Ev03o2oq3-GGOS2&index=4)
* 3. Lesson 5: Vertex Attributes (https://www.youtube.com/watch?v=x0H--CL2tUI&list=PLlrATfBNZ98foTJPJ_Ev03o2oq3-GGOS2&index=5)
* 4. Lesson 6: Shaders Intro (https://www.youtube.com/watch?v=5W7JLgFCkwI&list=PLlrATfBNZ98foTJPJ_Ev03o2oq3-GGOS2&index=6)
*/
namespace lesson {
	class ModernOpenGLBasicLesson : public OpenGLLesson {
	public:
		ModernOpenGLBasicLesson();

		int run() override;

	private:
		unsigned int compileShader(unsigned int, const std::string&);
		unsigned int createShaderProgram();
	};
}