#ifndef TREE_H
#define TREE_H

// ----- NODE -----

struct node {
    int value;
    struct node *left_child;
    struct node *right_child;
};

struct node *new_node(int value);

// ----- TREE -----

struct tree {
    int size;
    struct node *head;
};

struct tree *new_tree();

// ----- TREE FUNCTIONS -----

void add(struct tree *tree, int value);
struct node *r_add(struct node *node, int value);

void basic_print(struct node *node);
void print(struct tree *tree);
void r_print(struct node *head, int space);

int contains(struct tree *tree, int value);
int r_contains(struct node *node, int value);

#endif