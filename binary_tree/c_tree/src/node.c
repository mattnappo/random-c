#include <stdlib.h>
#include "tree.h"

struct node *new_node(int value) {
    struct node *node = malloc(sizeof(struct node));
    node->value = value;
    node->right_child = NULL;
    node->left_child = NULL;
    return node;
}

int get_value(struct node *node) {
    return node->value;
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