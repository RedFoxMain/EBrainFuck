#include <iostream>
#include <string>

#include "BrainFuck.h"

// BrainFuck <file|inter> [-m]

int main(int argc, char* argv[]){
	BrainFuck bf;
	if (argv[1] != NULL){
		// Interactive mode
		if (strcmp(argv[1], "inter") == 0) {
			std::string code;
			std::cout << ">> "; std::getline(std::cin, code);
			while (code != "ex") {
				try {
					bf.eval(code);
				} catch (std::exception& err) { std::cout << err.what() << "\n"; }
				if (argv[2] != NULL && strcmp(argv[2], "-m") == 0) {
					bf.printMem();
					bf.printStack();
				}
				bf.reset();
				std::cout << ">> "; std::getline(std::cin, code);
			}
		}else { // Code from file
			try {
				bf.eval(bf.readFromFile(argv[1]));
			} catch (std::exception& err) { std::cout << err.what() << "\n"; }
			if (argv[2] != NULL && strcmp(argv[2], "-m") == 0) {
				bf.printMem();
				bf.printStack();
			}
			bf.reset();
		}
	}
	return 0;
}