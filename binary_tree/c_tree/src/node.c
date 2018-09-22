#include <stdio.h>
#include "tree.h"

struct node {
    int value;
    struct node *left_child;
    struct node *right_child;
};

void print_value(struct node *node) {
    printf("value: %d\n", node->value);
}

void set_value(struct node *node, int value) {
    node->value = value;
}

struct node *get_right_child(struct node *node) {
    return node->right_child;
}

struct node *get_left_child(struct node *node) {
    return node->left_child;
}

int get_value(struct node *node) {
    return node->value;
}