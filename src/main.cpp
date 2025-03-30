#include <iostream>

#define MAX_SIZE 20

int main(){
	int* mem = new int[MAX_SIZE]{};
	int* ptr = mem;

	std::string s = "+++>++[<->+]";
	for (size_t i = 0; i < s.size(); ++i) {
		if(s[i] == '+') ++(*ptr);
		if(s[i] == '-') --(*ptr);
		if(s[i] == '>') ++ptr;
		if(s[i] == '<') --ptr;
		if (s[i] == '[') {
			if (*ptr == 0) {
				int brc = 1;
				while (brc > 0 && i < s.size()) {
					char curr_char = s[++i];
					if (curr_char == '[') brc++;
					if (curr_char == ']') brc--;
				}
			}
		}
		else if (s[i] == ']') {
			if (*ptr != 0) {
				int brc = 1;
				while (brc > 0 && i > 0) {
					char curr_char = s[--i];
					if (curr_char == '[') brc--;
					if (curr_char == ']') brc++;
				}
				--i;
			} else {
				++i;
			}
		}
	}
	std::cout << std::endl;
	for (size_t i = 0; i < MAX_SIZE; i++) {
		std::cout << mem[i] << " ";
	}
	return 0;
}