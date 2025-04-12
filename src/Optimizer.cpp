#include "Optimizer.h"

vector_of_pairs Optimizer::getBraces(const std::string& text) {
	std::stack<int> st;
	vector_of_pairs temp;
	for (size_t i = 0; i < text.size(); ++i) {
		if (text[i] == '[') st.push(i);
		if (text[i] == ']') {
			if (!st.empty()) {
				int pos = st.top(); st.pop();
				temp.push_back({ pos, i });
			}
		}
	}
	return temp;
}

int Optimizer::findOpenBrace(const vector_of_pairs& vec, size_t index) {
	auto iter = std::find_if(vec.begin(), vec.end(), [index](const auto& pair) {
		return pair.second == index;
	});
	return (iter != vec.end()) ? iter->first : -1;
}

int Optimizer::findCloseBrace(const vector_of_pairs& vec, size_t index) {
	auto iter = std::find_if(vec.begin(), vec.end(), [index](const auto& pair) {
		return pair.first == index;
	});
	return (iter != vec.end()) ? iter->second : -1;
}
