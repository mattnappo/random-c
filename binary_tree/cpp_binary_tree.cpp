#include <iostream>

class Node {
private:
    int value;
    Node *right_child;
    Node *left_child;
public:
    Node(int value = 0, Node *right_child = NULL, Node *left_child = NULL) {
        this->value = value;
        this->right_child = right_child;
        this->left_child = left_child;
    }

    void print_r(Node *node) {
        node->print_node();
        if (node->right_child != NULL) {
            print_r(node->right_child);
        }

        if (node->left_child != NULL) {
            print_r(node->left_child);
        }

    }

    void print_node() {
        std::cout << "value: " << value << std::endl;
    }

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

    Node *head = new Node(10);

    Node *right_child = new Node(20);
    right_child->set_right_child(new Node(25));
    right_child->set_left_child(new Node(30));

    Node *left_child = new Node(5);
    left_child->set_left_child(new Node(11));

    head->set_right_child(right_child);
    head->set_left_child(left_child);

    head->print_r(head);

    return 0;
}