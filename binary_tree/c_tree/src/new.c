#include <stdlib.h>
#include "tree.h"

struct node *new_node(int value) {
    struct node *node = malloc(sizeof(struct node));
    node->value = value;
    node->right_child = NULL;
    node->left_child = NULL;
    return node;
}

struct tree *new_tree() {
    struct tree *tree = malloc(sizeof(tree));
    tree->size = 0;
    tree->head = NULL;
    return tree;
}