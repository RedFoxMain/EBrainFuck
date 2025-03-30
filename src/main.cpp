#include <iostream>

#define MAX_SIZE 20

int main(){
	int* mem = new int[MAX_SIZE]{};
	int* ptr = mem;

	std::string s = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";
	for (size_t i = 0; i < s.size(); i++) {
		if (std::isspace(s[i])) continue;
		if (s[i] == '+') {
			++(*ptr);
			if (*ptr > 255) *ptr = 0;
		}
		if (s[i] == '-') { 
			--(*ptr); 
			if (*ptr < 0) *ptr = 255;
		}
		if (s[i] == '.') std::cout << (char)(*ptr);
		if (s[i] == '>') {
			++ptr;
			if (ptr >= mem + MAX_SIZE) { 
				ptr = mem + MAX_SIZE - 1;
			}
		}
		if (s[i] == '<') {
			if (ptr > mem) --ptr;
		}
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
			if(*ptr != 0) {
				int brc = 1;
				while (brc > 0 && i > 0) {
					char curr_char = s[--i];
					if (curr_char == '[') brc--;
					if (curr_char == ']') brc++;
				}
			}
		}
	}
	std::cout << std::endl;
	for (size_t i = 0; i < MAX_SIZE; i++) {
		std::cout << mem[i] << " ";
	}
	return 0;
}