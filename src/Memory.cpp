#include "Memory.h"

Memory::Memory() : memory_(new int[MEM_SIZE]{}), ptr_(memory_) {}
Memory::~Memory() {
	delete[] memory_;
}

// Increment byte at current pointer
void Memory::incByte() {
	++(*ptr_);
	if (*ptr_ > 255) *ptr_ = 0;
}

// Decrement byte at current pointer
void Memory::decByte() {
	--(*ptr_);
	if (*ptr_ < 0) *ptr_ = 255;
}

// Move pointer right
void Memory::incPtr() {
	++ptr_;
	if (ptr_ > memory_ + MEM_SIZE) throw std::runtime_error("Ptr out of range!");
}

// Move pointer left
void Memory::decPtr() {
	--ptr_;
	if (ptr_ < memory_) throw std::runtime_error("Ptr can not be negative!");
}

// Set value to current pointer
void Memory::memWrite(int val) {
	*ptr_ = val;
}

// Copy value from top of the stack
void Memory::copyFromStack() {
	*ptr_ = stack_.back();
}

// Pop value from top of the stack
void Memory::popFromStack() {
	if(stack_.empty()) throw std::runtime_error("Stack is empty!");
	stack_.pop_back();
}

// Push current pointer value to stack
void Memory::pushToStack() {
	stack_.push_back(*ptr_);
}

// Clear memory
void Memory::reset() {
	stack_.clear();
	std::fill(memory_, memory_ + MEM_SIZE, 0);
	ptr_ = memory_;
}

// Get current poinet value
int Memory::currVal() {
	return *ptr_;
}

// Return memory
int* Memory::getMem() {
	return memory_;
}

// Return stack
std::vector<int> Memory::getStack() {
	return stack_;
}