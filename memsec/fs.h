#include "memory.h"

struct file {
  char *bytes;
  size_t s;
};

struct fs {
  struct memory *mem;
  size_t *offsets;
  size_t *sizes;
  unsigned int fc;
};

// Make a new fs
struct fs *new_fs();

// Add a new file to an fs
int add_file(struct fs *fs, struct file *f, size_t offset);

// Remove a file from an fs
int remove_file(struct fs *fs, struct file *f);

// Construct a file given a filename
struct file *new_file(const char *name);

