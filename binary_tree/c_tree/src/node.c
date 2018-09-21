#include <stdio.h>
#include "tree.h"

struct node {
    int value;
    struct node *left_child;
    struct node *right_child;
};

void print_value(struct node *node) {
    printf("value: %d\n", node->value);
}

void set_value(struct node *node, int value) {
    node->value = value;
}