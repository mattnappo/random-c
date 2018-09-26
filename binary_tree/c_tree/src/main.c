#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

int main() {
    struct tree *m_tree = malloc(sizeof(struct tree));

    m_tree->size = m_tree->size + 1;
    m_tree->head = malloc(sizeof(struct node));
    printf("%d\n", m_tree->head->value);

    return 0;
}