#include <iostream>
#include <cmath>
#include <list>

int get(std::list<int>, int index) {
	
};

int search(std::list<int> l, int target) {
	int middle_index = floor(l.size() / 2);
	std::list<index> new_list;

	if (target > l.get(middle_index)) {
		for (int i = middle_index; i < l.size(); i++) {
			new_list.push_front(l.get(i));
		}
		return search(new_list, target);

	} else if (target < l.get(middle_index)) {
		for (int i = 0; i < middle_index; i++) {
			new_list.push_front(l.get(i));
		}
		return search(new_list, target);
	} else if (target == l.get(middle_index)) {
		return middle_index;
	}

	return 0;
};

int main() {
	std::list<int> a;
	for (int i = 0; i < 10; i++) {
		a.push_front(i);
	}
	search(a, 3);
	return 0;
};
