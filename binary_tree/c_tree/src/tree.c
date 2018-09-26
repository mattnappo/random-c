#include "tree.h"

int get_size(struct tree *tree) {
    return tree->size;
}

struct node *get_head(struct tree *tree) {
    return tree->head;
}

void set_size(struct tree *tree, int size) {
    tree->size = size;
}

void set_head(struct tree *tree, struct node *head) {
    tree->head = head;
}