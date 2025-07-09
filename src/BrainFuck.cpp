#include "BrainFuck.h"
#include "Optimizer.h"

BrainFuck::BrainFuck() {}

BrainFuck::~BrainFuck() {}

void BrainFuck::eval(const std::string& code) {
	vector_of_pairs vec = Optimizer::getBraces(code);
	for (size_t i = 0; i < code.size(); ++i) {
		if (std::isspace(code[i])) continue;
		if (code[i] == '#') memory_.pushToStack();
		if (code[i] == '$') memory_.copyFromStack();
		if (code[i] == '!') memory_.popFromStack();
		if (code[i] == '+') memory_.incByte();
		if (code[i] == '-') memory_.decByte();
		if (code[i] == '.') {
			in_output = true;
			std::cout << static_cast<char>(memory_.currVal());
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
			uint8_t value;
			if (in_output) std::cout << "\n";
			std::cout << "In: "; std::cin >> value;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			memory_.memWrite(value);
		}
		if (code[i] == '>') memory_.incPtr();
		if (code[i] == '<') memory_.decPtr();
		if (code[i] == '[') {
			if (memory_.currVal() == 0) {
				i = Optimizer::findCloseBrace(vec, i);
			}
		} else if (code[i] == ']') {
			if (memory_.currVal() != 0) {
				i = Optimizer::findOpenBrace(vec, i);
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
	uint8_t* mem = memory_.getMem();
	if (in_output) std::cout << "\n";
	for (size_t i = 0; i < MEM_SIZE; ++i) std::cout << static_cast<int>(mem[i]) << " ";
}

// Print stack
void BrainFuck::printStack() {
	std::cout << "\n";
	std::vector<uint8_t> st = memory_.getStack();
	if (!st.empty()) {
		for (const uint8_t& el : st) std::cout << static_cast<int>(el) << " ";
		std::cout << "\n";
	} else std::cout << "Stack < is empty >\n";
}