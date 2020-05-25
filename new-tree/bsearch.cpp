#include <iostream>
#include <cmath>
#include <vector>

void print_vec(std::vector<int> v) {
	std::cout << "{ ";
	for (int i = 0; i < v.size(); i++) {
		std::cout << i << " ";
	}
	std::cout << "}" << std::endl;
}

int search_(std::vector<int> v, int start, int end, int target) {
	int middle_index = floor(v.size() / 2);

	if (target > v.at(middle_index)) {
		return search_(v, middle_index, v.size() - middle_index, target);

	} else if (target < v.at(middle_index)) {
		return search_(v, 0, middle_index, target);
	} else if (target == v.at(middle_index)) {
		return middle_index;
	}

	return -1;
};

int search(std::vector<int> v, int target) {
	return search_(v, 0, v.size(), target);
};

int main() {
	std::vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	print_vec(v);
	std::cout << search(v, 3) << std::endl;
	return 0;
};
