#pragma once

#include <vector>

namespace opengl {
	namespace vertex {
		class EBO
		{
		public:
			EBO() {}
			EBO(std::vector<unsigned int>);
			EBO(EBO&) = default;
			EBO(EBO&&) = default;

			EBO& operator=(EBO&) = default;
			EBO& operator=(EBO&&) = default;

			~EBO();

			int getNumberOfIndices();

		private:
			unsigned int id;
			std::vector<unsigned int> buffer;
		};
	}
}