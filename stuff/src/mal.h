#ifndef MAL_H
#define MAL_H

#define MAX 10

#include <stdlib.h>
#include <stdio.h>

#include "rand.h"

struct hl_ {
    char *pld;
    struct hl_ *hl;
};

struct lhl_ {
    unsigned int c;
    struct hl_ **lhl;
};

struct lhl_ *new_lhl_(int max);
int print_lhl_(struct lhl_ *lhl);

#endif