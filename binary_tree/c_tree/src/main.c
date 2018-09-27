#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

int main() {
    struct tree *m_tree = new_tree();
    m_tree->head = new_node(50);
    
    add(m_tree, 70);
    add(m_tree, 60);
    add(m_tree, 80);

    return 0;
}