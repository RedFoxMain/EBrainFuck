#ifndef MEMORY_H
#define MEMORY_H

#define MEM_SIZE 32

#include <vector>
#include <stdexcept>

class Memory {
private:
	std::vector<int> stack_;
	int* memory_;
	int* ptr_;

public:
	Memory();
	~Memory();

	void incByte();
	void decByte();
	void incPtr();
	void decPtr();

	void memWrite(int val);
	void copyFromStack();
	void popFromStack();
	void pushToStack();

	void reset();
	int currVal();
	int* getMem();
	std::vector<int> getStack();
};
#endif // !MEMORY_H