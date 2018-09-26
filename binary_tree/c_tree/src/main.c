#include <stdlib.h>
#include <stdio.h>
// #include "tree.h"

struct tree {
    int size;
    struct node *head;
};

struct node {
    int value;
    struct node *left_child;
    struct node *right_child;
};

int main() {
    struct tree *m_tree = (struct tree *)malloc(sizeof(struct stree *));
    *m_tree->head->value = 10;
    

    // printf("%i\n", m_tree->head->value);
    //add(tree, 10);

    return 0;
}