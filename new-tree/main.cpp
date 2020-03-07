#include <iostream>

#define DEPTH 16

class Node {
	int value;
	Node *left;
	Node *right;
public:
	Node(int value, Node *left, Node *right) {
		this -> value = value;
		this -> left  = left;
		this -> right = right;
	}
	
	void Print() {
		printf("{%d, %p, %p}\n", value, left, right);
	};
};

class Tree {
	Node *Head;
	void AddValue() {
		
	}
};


int main() {
	// Node *node = new Node(10, NULL, NULL);
	// node -> Print();
	
	
	return 0;
}
