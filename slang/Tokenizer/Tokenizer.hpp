#pragma once
#include <iostream>
#include <vector>
#include <stack>

class Tokenizer {
private:
	std::string lr, rv;

public:
	std::vector<char> tokenizerPath;
	std::stack<std::string> calcStack;  // Stack for calculations, parentheses, etc.

public:
	Tokenizer(std::string& tokenPath);
	void setLR(std::string);
	void setRV(std::string);
	void setPath(std::string);
	void splitTokens(std::string);
	void processTokens(std::vector<std::string>);
};