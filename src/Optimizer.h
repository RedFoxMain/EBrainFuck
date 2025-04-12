#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include <vector>
#include <string>
#include <stack>
#include <stdexcept>
#include <algorithm>

using vector_of_pairs = std::vector<std::pair<int, int>>;

class Optimizer {
public:
	Optimizer();
	~Optimizer();
	
	static vector_of_pairs getBraces(const std::string& text); // Save position of [ and ] in vector
	static int findOpenBrace(const vector_of_pairs& vec, size_t index); // Find [ for ]
	static int findCloseBrace(const vector_of_pairs& vec, size_t index); // Find ] for [

};
#endif // !OPTIMIZER_H