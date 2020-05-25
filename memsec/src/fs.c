#include "fs.h"

struct file *new_file(const char *name)
{
  struct file *f = malloc(sizeof(struct file *));
  size_t fsize, read_size;
  FILE *fp = fopen(name, "r");

  if (fp) {
    fseek(fp, 0, SEEK_END);
    fsize = ftell(fp);
    f->bytes = malloc(sizeof(char) * (fsize + 1));

    rewind(fp);
    read_size = fread(f->bytes, sizeof(char), fsize, fp);

    f->bytes[fsize] = '\0';
    f->s = read_size;

    if (fsize != read_size) {
      free(f->bytes);
      f->bytes = NULL;
      f->s = 0;
    }

    fclose(fp);
  }

  return f;
}

struct fs *new_fs()
{
  struct fs *fs = malloc(sizeof(struct fs *));
  fs->mem = malloc(sizeof(struct memory *));
  fs->mem = new_memory();
  return fs;
}

int add_file(struct fs *fs, struct file *f, size_t offset) {
  // write_file(fs->mem, f, offset);
  return 0;
}

int remove_file();

