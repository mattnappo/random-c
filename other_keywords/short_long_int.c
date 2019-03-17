#include <stdlib.h>

/*
    There are four types of int/float/double...
    1. signed - inferred by the compiler
    2. unsigned - no negative, larger positive
    3. short - 2 bytes
    4. long - 4 bytes
*/

int main() {

    signed int a = 10; // signed is automatic (by the compiler)

    unsigned int b = 5;

    short int c = 10;

    long int d = 10;

    // You can also have

    long double g = 723.237656;

    // These two are the same
    unsigned long int e = 91829736;
    unsigned long f = 872763;


    return 0;
}