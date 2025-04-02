#include "BrainFuck.h"

BrainFuck::BrainFuck() {}

BrainFuck::~BrainFuck() {}

void BrainFuck::eval(const std::string& code) {
	for (size_t i = 0; i < code.size(); ++i) {
		if (std::isspace(code[i])) continue;
		if (code[i] == '#') memory_.pushToStack();
		if (code[i] == '$') memory_.copyFromStack();
		if (code[i] == '!') memory_.popFromStack();
		if (code[i] == '+') memory_.incByte();
		if (code[i] == '-') memory_.decByte();
		if (code[i] == '.') {
			in_output = true;
			std::cout << (char)memory_.currVal();
		}
		if (code[i] == ':') std::cout << memory_.currVal();
		if (code[i] == ',') {
			char symbol;
			if (in_output) std::cout << "\n";
			std::cout << "In: "; std::cin >> symbol;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			memory_.memWrite(symbol);
		}
		if (code[i] == ';') {
			int value;
			if (in_output) std::cout << "\n";
			std::cout << "In: "; std::cin >> value;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (value < 0 || value > 255) throw std::runtime_error("Value must be represented by a byte!");
			memory_.memWrite(value);
		}
		if (code[i] == '>') memory_.incPtr();
		if (code[i] == '<') memory_.decPtr();
		if (code[i] == '[') {
			if (memory_.currVal() == 0) {
				int brc = 1;
				while (brc > 0 && i < code.size()) {
					char curr_char = code[++i];
					if (curr_char == '[') brc++;
					if (curr_char == ']') brc--;
				}
			}
		} else if (code[i] == ']') {
			if (memory_.currVal() != 0) {
				int brc = 1;
				while (brc > 0 && i > 0) {
					char curr_char = code[--i];
					if (curr_char == '[') brc--;
					if (curr_char == ']') brc++;
				}
			}
		}
	}
}

// Read code from file
std::string BrainFuck::readFromFile(const char* file_name) {
	std::string code;
	std::ifstream file(file_name);
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) code += line;
	}
	file.close();
	return code;
}

void BrainFuck::reset() {
	in_output = false;
	memory_.reset();
}

// Print mem
void BrainFuck::printMem() {
	int* mem = memory_.getMem();
	if (in_output) std::cout << "\n";
	for (size_t i = 0; i < MEM_SIZE; ++i) std::cout << mem[i] << " ";
}

// Print stack
void BrainFuck::printStack() {
	std::cout << "\n";
	std::vector<int> st = memory_.getStack();
	if (!st.empty()) {
		for (const int& el : st) std::cout << el << " ";
		std::cout << "\n";
	} else std::cout << "Stack < is empty >\n";
}