#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BSIZE 1024
#define FCOUNT BSIZE

enum print_mode {
  HEX,
  DEC
};

struct memory {
  char *bytes;
  size_t s;
};

// Construct a new memory struct
struct memory *new_memory();

// Print out the contents of a memory
int dump(struct memory *mem, enum print_mode m);

// Write bytes to a memory
int write(struct memory *mem, char *b, size_t s, size_t offset);

// Write a file to a memory
// int write_file(struct memory *mem, struct file *f, size_t offset);

