#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

int main() {
    printf("WORKING\n");
    struct tree *tree = malloc(sizeof(struct tree));
    
    add(tree, 10);
    
    return 0;
}