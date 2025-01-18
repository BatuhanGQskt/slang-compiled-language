#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

enum FileStatus : int
{
	SuccessFile = 1, FailFile = -1, UndefinedFile = NULL, NotSetFile = 0
};

class FileHandler {
protected:
	std::string filePath;
	std::ifstream file_stream;
	std::vector<char> file_buffer;
	FileStatus status;

public:
	std::string error_msg;

public:
	FileHandler() = delete;
	FileHandler(const std::string&);
	~FileHandler();
	std::string readFile();
	void setFileStatus(FileStatus);

};