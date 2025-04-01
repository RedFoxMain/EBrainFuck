#include <iostream>
#include "BrainFuck.h"

int main(){
	BrainFuck bf;
	std::string s = "++++";
	bf.eval(s);
	bf.printMem();
	bf.printStack();
	return 0;
}