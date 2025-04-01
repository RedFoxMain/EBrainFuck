#ifndef BRAINFUCK_H
#define BRAINFUCK_H

#include <iostream>
#include "Memory.h"

class BrainFuck {
private:
	Memory memory_;

public:
	BrainFuck();
	~BrainFuck();

	void eval(const std::string& code);
	void reset();

	void printMem();
	void printStack();
};
#define BRAINFUCK_H
#endif // !BRAINFUCK_H