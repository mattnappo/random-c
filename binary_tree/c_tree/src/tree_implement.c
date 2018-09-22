#include "tree.h"

void add(struct tree *tree, int value) {
    set_size(tree, get_size(tree) + 1);
    struct node *head = get_head(tree);
    set_head(tree, r_add(head, value));
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
