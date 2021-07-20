#pragma once

#include <vector>

namespace opengl {
	namespace vertex {
		class VBO
		{
		public:
			VBO() {}
			VBO(std::vector<float>);
			VBO(VBO&) = default;
			VBO(VBO&&) = default;

			VBO& operator=(VBO&) = default;
			VBO& operator=(VBO&&) = default;

			~VBO();

		private:
			unsigned int id;
			std::vector<float> buffer;
		};
	}
}