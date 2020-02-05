#include <stdlib.h>
#include <stdio.h>

#define BSIZE 1024
#define FSIZE 128

struct file {
    char * bytes;
    size_t len;
};

struct file new_file(char *b) {
    struct file f = { b, strlen(a) };
    return f;
}

struct memory {
    char * bytes;
    size_t * f_sizes;
};

struct memory *new_memory() {
    struct memory *mem = malloc(sizeof(struct memory *));
    mem -> bytes = malloc(sizeof(char) * BSIZE);
    mem -> f_sizes = malloc(sizeof(char) * FSIZE);
    return mem;
}

int dump(struct memory *mem) {
    printf("%s", mem -> bytes);
    return 0;
}

int write_file(struct memory *mem, struct file file, int position) {
    if (position > BSIZE) {
        printf("invalid position");
        return 1;
    }

    for (int i = position; i < file -> len; i++) {
        mem -> bytes[i] = file -> bytes[i];
    }

    return 0;
}

int main() {
    struct memory *mem = new_memory();
    dump(mem);

    return 0;
}