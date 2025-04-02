#ifndef BRAINFUCK_H
#define BRAINFUCK_H

#include <iostream>
#include <fstream>
#include <string>

#include "Memory.h"

class BrainFuck {
private:
	Memory memory_;
	bool in_output = false;
public:
	BrainFuck();
	~BrainFuck();

	void eval(const std::string& code);
	std::string readFromFile(const char* file_name);
	void reset();

	void printMem();
	void printStack();
};
#define BRAINFUCK_H
#endif // !BRAINFUCK_H