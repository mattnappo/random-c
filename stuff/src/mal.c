#include "mal.h"

struct lhl_ *new_lhl_(int max)
{
    struct lhl_ *lhl = (struct lhl_ *)malloc(sizeof(struct lhl_ *));
    lhl->lhl = (struct hl_ **)malloc(sizeof(struct hl_ *) * MAX);
    
    for (unsigned int i = 0; i < max-1; i++) {
        struct hl_ *hl;

        if (i == 0) {
            hl = malloc(sizeof(struct hl_ *));
            hl->pld = read_rand();
            hl->hl  = NULL;
        } else {
            hl->pld = read_rand();
            hl->hl  = lhl->lhl[i-1];
        } 
    
        lhl->lhl[i] = hl;
        lhl->c++;
    }

    return lhl;
}

int print_lhl_(struct lhl_ *lhl)
{
    for (unsigned int i = 0; i < lhl->c; i++) {
        printf("[hl_]\n  pld: {%s}\n  hl_: {\n    pld: {%s}\n  }\n",
            lhl->lhl[i]->pld, lhl->lhl[i]->hl->pld);
    }
    return 0;
}

int main()
{
    struct lhl_ *lhl = new_lhl_(MAX); // pake the lhl
    print_lhl_(lhl); // print the lhl

    return 0;
}