#include "rand.h"

char *read_rand()
{
    FILE *f;
    char *buffer = malloc(sizeof(char) * BUFF_SIZE);
    f = fopen("/dev/random", "r");
    if (f == NULL) return 0x0;
    
    char c = fgetc(f);
    for (int i = 0; i < BUFF_SIZE; i++) {
        if (c == EOF) break;
        buffer[i] = fgetc(f);
    }
    
    fclose(f);
    return buffer;
}