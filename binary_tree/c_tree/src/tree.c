#include <stdlib.h>
#include "tree.h"

struct tree *new_tree() {
    struct tree *tree = malloc(sizeof(tree));
    tree->size = 0;
    tree->head = NULL;
    return tree;
}

int get_size(struct tree *tree) {
    return tree->size;
}

void set_size(struct tree *tree, int size) {
    tree->size = size;
}

struct node *get_head(struct tree *tree) {
    return tree->head;
}

void set_head(struct tree *tree, struct node *head) {
    tree->head = head;
}