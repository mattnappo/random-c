#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void add(struct tree *tree, int value) {
    tree->size = tree->size + 1;
    
    r_add(tree->head, value);
}

struct node *r_add(struct node *node, int value) {
    struct node *new_node = malloc(sizeof(node));
    new_node->value = value;
    if (node == 0) {
        printf("this is happening\n");
        node->value = value;
    } else if (value <= node->value) {
        struct node *left = node->left_child;
        left = r_add(node->left_child, value);
    } else {
        struct node *right = node->right_child;
        right = r_add(node->right_child, value);
    }
    return node;
}