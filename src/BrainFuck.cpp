#include "BrainFuck.h"

BrainFuck::BrainFuck() {}

BrainFuck::~BrainFuck() {}

void BrainFuck::eval(const std::string& code) {
	for (size_t i = 0; i < code.size(); ++i) {
		if (std::isspace(code[i])) continue;
		if (code[i] == '+') memory_.incByte();
		if (code[i] == '-') memory_.decByte();
		if (code[i] == '.') std::cout << (char)(memory_.currVal());
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

void BrainFuck::reset() {
	memory_.reset();
}

// Print mem
void BrainFuck::printMem() {
	int* mem = memory_.getMem();
	std::cout << "\n";
	for (size_t i = 0; i < MEM_SIZE; ++i) {
		std::cout << mem[i] << " ";
	}
}

// Print stack
void BrainFuck::printStack() {
	std::cout << "\n";
	std::vector<int> st = memory_.getStack();
	if (!st.empty()) {
		for (const int& el : st) {
			std::cout << el << " ";
		}
	} else std::cout << "Stack < is empty >";
}
