#include <string.h>
#include "memory.h"

#ifndef FS_H
#define FS_H

#define FILENAME_SIZE 16
#define MAX_FILES     16

struct file {
    char *bytes;
    size_t s;
    size_t offset;
    char name[FILENAME_SIZE];
};

struct f_table {
    // Implement hashmap later
    struct file *files[MAX_FILES];
    size_t f_count;
};

struct fs {
    struct memory *mem;
    struct f_table *ft;
};

// Make a new fs
struct fs *new_fs();

// Add a new file to an fs
int add_file(struct fs *fs, struct file *f, size_t offset);

// Remove a file from an fs
int remove_file(struct fs *fs, struct file *f);

// Construct a file given a filename
struct file *new_file(const char *name);

// Construct a new f_table
struct f_table *new_f_table();

// Add a file entry into the f_table
int add_f_table_entry(struct f_table *ft, struct file *f);

#endif

