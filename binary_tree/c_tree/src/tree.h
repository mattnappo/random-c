#ifndef TREE_H
#define TREE_H

// ----- NODE -----

struct node;
void print_value(struct node *node);
void set_value(struct node *node, int value);

struct node *get_right_child(struct node *node);
struct node *get_left_child(struct node *node);

int get_value(struct node *node);

// ----- TREE -----

struct node *r_add(struct node *node, int value);


#endif