#ifndef TREE_H
#define TREE_H

// ----- NODE -----

struct node {
    int value;
    struct node *left_child;
    struct node *right_child;
};
struct node *new_node(int value);

void set_value(struct node *node, int value);
int get_value(struct node *node);

struct node *get_right_child(struct node *node);
struct node *get_left_child(struct node *node);

// ----- TREE -----

struct tree {
    int size;
    struct node *head;
};
struct tree *new_tree();

int get_size(struct tree *tree);
void set_size(struct tree *tree, int size);

struct node *get_head(struct tree *tree);
void set_head(struct tree *tree, struct node *head);

// ----- TREE FUNCTIONS -----

void add(struct tree *tree, int value);
struct node *r_add(struct node *node, int value);

void basic_print(struct node *node);
void print(struct tree *tree);
void r_print(struct node *head, int space);

int contains(struct tree *tree, int value);
int r_contains(struct node *node, int value);

#endif