#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void add(struct tree *tree, int value) {
    set_size(tree, get_size(tree) + 1);
    r_add(get_head(tree), value);
}

struct node *r_add(struct node *node, int value) {
    // struct node *new_node = malloc(sizeof(node));
    // new_node->value = value;
    if (node == 0) {
        printf("this is happening\n");
        set_value(node, value);
    } else if (value <= node->value) {
        struct node *left = get_left_child(node);
        left = r_add(get_left_child(node), value);
    } else {
        struct node *right = get_right_child(node);
        right = r_add(get_right_child(node), value);
    }
    return node;
}