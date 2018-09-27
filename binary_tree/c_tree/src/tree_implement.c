#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#define SPACE 10 

void add(struct tree *tree, int value) {
    tree->size = tree->size + 1;
    printf("size: %d\n", tree->size);
    r_add(tree->head, value);
}


struct node *r_add(struct node *node, int value) {
    if (node == NULL) {
        return new_node(value);
    }
    if (value < node->value) {
        node->left_child = r_add(node->left_child, value);
    } else if (value > node->value) {
        node->right_child = r_add(node->right_child, value);
    }
    return node;
}

void r_print(struct node *head, int space) {
    if (head == NULL) {
        return;
    }
    space += SPACE;
    r_print(head->right_child, space);
    printf("\n");
    for (int i = SPACE; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", head->value);
    r_print(head->left_child, space);
} 


void print(struct tree *tree) {
   r_print(tree->head, 0);
} 


void basic_print(struct node *node) {
    if (node != NULL) {
        basic_print(node->left_child);
        printf("%d \n", node->value);
        basic_print(node->right_child);
    }
}

// struct node *r_add(struct node *node, int value) {
//     // struct node *new_node = malloc(sizeof(node));
//     // new_node->value = value;
//     // printf("%d\n", node->value);
//     //printf("%s", node);
//     // node = malloc(sizeof(node));
//     // node->value = 10;
//     // printf("VAL: %d\n", node->right_child->value);
//     // printf("VAL: %d\n", node->left_child->value);
    
//     if (node) {
//         printf("ya\n");
//         node = malloc(sizeof(node));
//         node->value = value;
//     // } else if (value <= node->value) {
        
//     //     //struct node *left = node->left_child;
//     //     node->left_child = malloc(sizeof(node));
//     //     //node->left_child = r_add(node->left_child, value);
//     // } else {
//     //     // printf("ya\n");
//     //     node->right_child = malloc(sizeof(node));
//     //     //node->right_child = r_add(node->right_child, value);
//     // }
//     }
//     return node;
// }


void print_tree(struct tree *tree) {
    _print_tree(get_head(tree));
}
    
void _print_tree(struct node *node) {
    if (node != 0) {
        printf("%i\n", node->value);
        _print_tree(node->left_child);
        _print_tree(node->right_child);
    }
}