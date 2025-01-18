#include <iostream>
#include "./file_handler/file_handler.hpp"
#include "./Tokenizer/Tokenizer.hpp"

#define TOKEN_PATH "./Tokenizer/Tokens.slgtk"

int main(int argc, const char* argv[]) {

    std::cout << "Argc vals: " << argc << std::endl;
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << std::endl;

    }


    // Check if a file path argument was provided
    if (argc < 2) {
        std::cerr << "Error: No file path provided.\n";
        std::cerr << "Usage: " << argv[0] << " <file_path>\n";
        return 1;
    }

    std::cout << "Trying to read file: " << argv[argc-1] << std::endl;

    const std::string path = argv[argc - 1];
    FileHandler* fileHandler = new FileHandler(path);
    
    std::string readLine = fileHandler->readFile();

    std::string tokenPath = std::string(TOKEN_PATH);
    Tokenizer tokenizer(tokenPath);

    tokenizer.splitTokens(readLine);

    return 0;
}