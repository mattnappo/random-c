#include <string.h>
#include "memory.h"

#ifndef FS_H
#define FS_H

#define FILENAME_SIZE 16
#define MAX_FILES     16

// A file, as represented in an ftable.
struct file {
    char name[FILENAME_SIZE];
    char *bytes;
    size_t s;
    size_t offset;
};

struct ftable {
    struct file *files[MAX_FILES];
    size_t f_count;
};

struct fs {
    struct memory *mem;
    struct ftable *ft;
};

// Make a new fs
struct fs *new_fs();

// Add a new file to an fs
int add_file(struct fs *fs, struct file *f, size_t offset);

// Remove a file from an fs
int remove_file(struct fs *fs, struct file *f);

// Construct a file given a filename
struct file *new_file(const char *name);

// Construct a new ftable
struct ftable *new_ftable();

// Add a file entry into the ftable
int add_ftable_entry(struct ftable *ft, struct file *f);

#endif

