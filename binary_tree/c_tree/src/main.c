#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

struct tree *new_tree() {
    struct tree *tree = malloc(sizeof(tree));
    tree->size = 0;
    tree->head = NULL;
    return tree;
}

struct node *new_node(int value) {
    struct node *node = malloc(sizeof(struct node));
    node->value = value;
    node->right_child = NULL;
    node->left_child = NULL;
    return node;
}

int main() {
    struct tree *m_tree = new_tree();
    //m_tree->head = malloc(sizeof(struct node));
    // m_tree->head->value = 10;
    // printf("%d\n", m_tree->head->value);
    // add(m_tree, 10);
    // add(m_tree, 5);
    m_tree->head = new_node(50);
    // r_add(m_tree->head, 30);
    // r_add(m_tree->head, 20);
    // r_add(m_tree->head, 40);
    // r_add(m_tree->head, 70);
    // r_add(m_tree->head, 60);
    // r_add(m_tree->head, 80);
    
    add(m_tree, 70);
    add(m_tree, 60);
    add(m_tree, 80);

    printf("%d\n", m_tree->head->value);

    inorder(m_tree->head);

    // printf("%d\n", m_tree->head->right_child->value);
    // printf("%d\n", m_tree->head->left_child->value);




    // struct node *node = new_node(10);

    // printf("%d\n", node->value);

    return 0;
}