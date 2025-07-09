#ifndef MEMORY_H
#define MEMORY_H

#define MEM_SIZE 32

#include <vector>
#include <stdint.h>
#include <stdexcept>

class Memory {
private:
	std::vector<uint8_t> stack_;
	uint8_t* memory_;
	uint8_t* ptr_;

public:
	Memory();
	~Memory();

	void incByte();
	void decByte();
	void incPtr();
	void decPtr();

	void memWrite(uint8_t val);
	void copyFromStack();
	void popFromStack();
	void pushToStack();

	void reset();
	int currVal();
	uint8_t* getMem();
	std::vector<uint8_t> getStack();
};
#endif // !MEMORY_H