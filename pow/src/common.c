#include "include.h"
#include <time.h>

#define BUFF_SIZE 50

unsigned long generate_random_bytes() {
    srand(time(NULL));
    unsigned long final;
    
    for (int i = 0; i < (1 + rand()) % 10; i++) {
        final += (long) rand();
    }

    return final;
}

unsigned long hash(const char *bytes) {
    unsigned long hash = 5381;
    int c;

    while (c = *bytes++)
        hash = ((hash << 5) + hash) + c;

    return hash;
}

char *unsigned_long_tostring(unsigned long ul) {
    char *buffer = (char *) malloc(BUFF_SIZE * sizeof(char));
    int n = sprintf(buffer, "%lu", ul);
    return buffer;
}

int write_to_file(char *path, char* bytes) {
    FILE *fp;
    fp = fopen(path, "w+");
    fprintf(fp, "%s", bytes);
    fclose(fp);
    return 1;
}