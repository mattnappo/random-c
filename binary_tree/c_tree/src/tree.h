#ifndef TREE_H
#define TREE_H

// ----- NODE -----

struct node {
    int value;
    struct node *left_child;
    struct node *right_child;
};

void print_value(struct node *node);
void set_value(struct node *node, int value);

struct node *get_right_child(struct node *node);
struct node *get_left_child(struct node *node);

int get_value(struct node *node);
struct node *new_node(int value);

// ----- TREE -----

struct tree {
    int size;
    struct node *head;
};

int get_size(struct tree *tree);
struct node *get_head(struct tree *tree);

void set_size(struct tree *tree, int size);
void set_head(struct tree *tree, struct node *head);

void print_tree(struct tree *tree);
void _print_tree(struct node *node);

void inorder(struct node *root);

// ----- TREE FUNCTIONS -----

void add(struct tree *tree, int value);
struct node *r_add(struct node *node, int value);

#endif