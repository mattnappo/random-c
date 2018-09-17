#include <iostream>
#include <iostream>

class Node {
private:
    int value;
    Node *right_child;
    Node *left_child;
public:
    void set_value(int value) {
        this->value = value;
    }
    void set_right_child(Node *right_child) {
        this->right_child = right_child;
    }
    void set_left_child(Node *left_child) {
        this->left_child = left_child;
    }

    int get_value() {
        return value;
    }
    Node *get_right_child() {
        return right_child;
    }
    Node *get_left_child() {
        return left_child;
    }

};

class Tree {
public:
    Tree() {

    }

    ~Tree() {

    }
};

int main() {
    
    return 0;
}