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
    struct node *m_node;
    m_node->value = 10;
    printf("%d\n", m_node->value); // WORKS FINE
    
    struct tree *m_tree;
    m_tree->head = m_node;
    printf("%d\n", m_tree->head->value);


    return 0;
}