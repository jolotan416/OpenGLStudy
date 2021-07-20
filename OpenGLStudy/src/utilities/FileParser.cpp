#include <iostream>

#include <utilities/FileParser.h>

namespace utilities {
	FileParser::FileParser(std::string fname) {
		std::cout << "Creating file with filename: " << fname << std::endl;
		inputFile = std::make_unique<std::ifstream>(fname);
		filename = fname;
	}

	FileParser::~FileParser() {
		inputFile->close();
	}

	std::string FileParser::parseFile() {
		if (!inputFile || !inputFile->is_open()) {
			std::cout << filename << " not found. Returning empty string";

			return "";
		}

		std::string tempBuffer;
		std::string buffer = "";
		while (!inputFile->eof()) {
			std::getline(*inputFile, tempBuffer);
			buffer += tempBuffer + "\n";
		}

		inputFile->clear();
		inputFile->seekg(0, std::ios::beg);

		return buffer;
	}
}