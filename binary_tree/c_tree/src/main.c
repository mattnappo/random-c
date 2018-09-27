#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

int main() {
    struct tree *m_tree = malloc(sizeof(struct tree));
    m_tree->head = malloc(sizeof(struct node));
    // m_tree->head->value = 10;
    // printf("%d\n", m_tree->head->value);
    add(m_tree, 10);
    // add(m_tree, 15);
    // add(m_tree, 5);

    

    // print_tree(m_tree);

    return 0;
}