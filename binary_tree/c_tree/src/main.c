#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

int main() {
    struct tree *m_tree = new_tree();
    m_tree->head = new_node(10);
    
    for (int i = 0; i < 30; i+=5) {
        add(m_tree, i);
        add(m_tree, i - 3);
    }
    
    print(m_tree);

    printf("%d\n", contains(m_tree, 10));   // 1
    printf("%d\n", contains(m_tree, 7));    // 1
    printf("%d\n", contains(m_tree, 5));    // 1
    printf("%d\n", contains(m_tree, 15));   // 1
    printf("%d\n", contains(m_tree, 1000)); // 0

    return 0;
}