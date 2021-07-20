#pragma once

#include <fstream>
#include <memory>
#include <string>

namespace utilities {
	class FileParser {
	public:
		FileParser(std::string);
		FileParser(FileParser&) = default;
		FileParser(FileParser&&) = default;

		FileParser& operator=(FileParser&) = default;
		FileParser& operator=(FileParser&&) = default;

		std::string parseFile();

		~FileParser();

	private:
		std::unique_ptr<std::ifstream> inputFile;
		std::string filename;
	};
}