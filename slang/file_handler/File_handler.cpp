#include "file_handler.hpp"

FileHandler::FileHandler(const std::string& path) : filePath(path) {
    file_stream.open(path);
    if (!file_stream.is_open()) {
        error_msg = "Failed to open file: " + path;
        setFileStatus(UndefinedFile);
    }
    else {
        setFileStatus(SuccessFile);
    }
}

FileHandler::~FileHandler() {
    if (file_stream.is_open()) {
        file_stream.close();
    }
}


void FileHandler::setFileStatus(FileStatus status) {
    this->status = status;
}



std::string FileHandler::readFile() {
    try {
        std::string temp_buffer;
        std::getline(file_stream, temp_buffer, ';');  // Read into string

        file_buffer.assign(temp_buffer.begin(), temp_buffer.end());  // Copy to vector

    }
    catch(std::iostream::failure& e) {
        std::cerr << "File stream error: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string str(file_buffer.begin(), file_buffer.end());
    return str;
}