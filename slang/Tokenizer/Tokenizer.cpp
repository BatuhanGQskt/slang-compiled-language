#include "Tokenizer.hpp"
#include <sstream>
#include <vector>
#include <iostream>
#include <regex>

Tokenizer::Tokenizer(std::string& tokenPath) {
	tokenizerPath.assign(tokenPath.begin(), tokenPath.end());
}


void Tokenizer::splitTokens(std::string line) {
    std::cout << "Before split: " << line << std::endl;

    std::vector<std::string> tokens;
    std::string token;
    bool inQuotes = false;
    std::string currentToken;

    for (size_t i = 0; i < line.length(); ++i) {
        char c = line[i];

        if (c == '"') {
            inQuotes = !inQuotes;  // Toggle quote state
            if (!inQuotes) {
                tokens.push_back(currentToken);
                currentToken.clear();
            }
        }
        else if (isspace(c) && !inQuotes) {
            if (!currentToken.empty()) {
                tokens.push_back(currentToken);
                currentToken.clear();
            }
        }
        else {
            currentToken += c;
        }
    }

    // Push the last token if it exists
    if (!currentToken.empty()) {
        tokens.push_back(currentToken);
    }

    // Print tokens for verification
    for (const auto& t : tokens) {
        std::cout << "Token: [" << t << "]" << std::endl;
    }

    std::cout << "After split." << std::endl;
}

void Tokenizer::processTokens(std::vector<std::string> tokens) {
    for (const auto& token : tokens) {
        if (token == "(" || token == ")") {
            // Push parentheses onto the stack
            calcStack.push(token);
        }
        else {
            // Handle numbers, operators, or other tokens
            calcStack.push(token);
        }
    }

    // Debug: Print stack content
    std::cout << "Stack content (top to bottom):" << std::endl;
    while (!calcStack.empty()) {
        std::cout << calcStack.top() << std::endl;
        calcStack.pop();  // Pop each item from the stack
    }
}