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

struct node *new_node(int value) {
    struct node *m_node;
    m_node->value = value;
    return m_node;
}
int main() {
    struct node *m_node;
    
    m_node->value = 10;
    m_node->right_child = new_node(15);
    m_node->left_child = new_node(5);
    
    printf("%d\n", m_node->value);


    struct tree *m_tree;
    m_tree->head = m_node;
    // printf("%d\n", m_tree->head->value);


    return 0;
}