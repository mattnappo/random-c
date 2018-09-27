#include <stdlib.h>
#include "tree.h"

int main() {
    struct tree *m_tree = new_tree();
    m_tree->head = new_node(10);
    
    for (int i = 0; i < 50; i+=5) {
        add(m_tree, i);
        add(m_tree, i - 3);
    }
    
    print(m_tree);

    return 0;
}