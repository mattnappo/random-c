#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MEM_SIZE 1024

enum print_mode {
  HEX,
  ASCII
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

