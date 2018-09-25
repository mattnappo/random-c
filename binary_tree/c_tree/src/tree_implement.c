#include "tree.h"

void add(struct tree *tree, int value) {
    tree->size = tree->size + 1;
    r_add(tree->head, value);
}

struct node *r_add(struct node *node, int value) {
    if (node == 0) {
        set_value(node, value);
    } else if (value <= get_value(node)) {
        struct node *left = get_left_child(node);
        left = r_add(get_left_child(node), value);
    } else {
        struct node *right = get_right_child(node);
        right = r_add(get_right_child(node), value);
    }
    return node;
}