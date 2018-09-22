// def add(self, x):
// self.size += 1
// self.root = self._add(self.root, x)

// def _add(self, node, x):
// if (node == None):
//     node = BinaryNode(x)
// elif (x <= node.getData()):
//     node.left = self._add(node.getLeft(), x)
// else:
//     node.right = self._add(node.getRight(), x)

// return node

#include "tree.h"

int size;
struct node *head;

void add(int value) {
    size ++;
    head = r_add(head, value);
}

struct node *r_add(struct node *node, int value) {
    if (node == 0) {
        set_value(node, value);
    } else if (value <= get_value(node)) {
        struct node *left = get_left_child(node);
        left = r_add(get_left_child(node), value);
    } else {
        struct node *right = get_right_child(node);
        right = r_add(get_right_child(node), value);
    }

    return node;
}