#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

int main() {
    struct tree *m_tree = malloc(sizeof(struct tree));
    m_tree->head = malloc(sizeof(struct node));
    
    printf("%d\n", m_tree->head->value);

    return 0;
}