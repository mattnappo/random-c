#include <iostream>
#include <iostream>

struct node {
    int value;
    struct node *right_child;
    struct node *left_child;
};

class Tree {
public:
    Tree() {

    }

    ~Tree() {

    }
};

int main() {

    struct node head;
    head.value = 10;

    struct node right_child;
    right_child.value = 15;

    struct node left_child;
    left_child.value = 5;

    std::cout << right_child.value << std::endl;
    std::cout << left_child.value << std::endl;

    // head.right_child = right_child;
    // head.left_child = left_child;

    // std::cout << head.value << std::endl;
    // std::cout << head.right_child->value << std::endl;
    // std::cout << head.left_child->value << std::endl;

    return 0;
}