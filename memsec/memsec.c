#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BSIZE 1024

enum print_mode {
  HEX,
  DEC
};

struct file {
  char *bytes;
  size_t s;
};

struct file *new_file(const char *name)
{
  struct file *f = malloc(sizeof(struct file *));

  size_t fsize, read_size;
  FILE *fp = fopen(name, "r");

  if (fp) {
    fseek(fp, 0, SEEK_END);
    fsize = ftell(fp);
    f->bytes = malloc(sizeof(char) * fsize);
    f->s = fsize;

    rewind(fp);
    read_size = fread(f->bytes, sizeof(char), fsize, fp);

    if (fsize != read_size) {
      free(f->bytes);
      f->bytes = NULL;
      f->s = 0;
    }

    fclose(fp);
  }

  return f;
}

struct memory {
  char *bytes;
  size_t s;
};

struct memory *new_memory()
{
  struct memory *mem = malloc(sizeof(struct memory *));
  mem->bytes   = malloc(sizeof(char) * BSIZE);
  mem->s       = sizeof(char) * BSIZE;
  return mem;
}

int dump(struct memory *mem, enum print_mode m)
{
  printf("\n=== BEGIN DUMP ===\n");
  for (int i = 0; i < mem->s; i++) {
    if (mem->bytes[i] == 0) {
      printf("%s", (m == HEX) ? "00 " : " ");
    }
	else if (m == HEX) {
      printf("%x ", mem->bytes[i]);
    }
    else if (m == DEC) {
      printf("%c", mem->bytes[i]);
    }
  }
  printf("\n=== END DUMP ===\n");
  return 0;
}

int write(
  struct memory *mem,
  char *b,
  size_t s,
  size_t offset
)
{
  if (s + offset >= mem->s) {
    printf("buffer is too big.\n");
    return 1;
  }
  for (size_t i = 0; i < s; i++) {
    mem->bytes[i + offset] = b[i];
  }
  return 0;
}

int write_file(
  struct memory *mem,
  struct file *f,
  size_t offset
)
{
  if (f->s + offset >= mem->s) {
    printf("buffer is too big.\n");
    return 1;
  }
  for (size_t i = 0; i < f->s; i++) {
    mem->bytes[i + offset] = f->bytes[i];
  }
  return 0;
}

int main()
{
  struct memory *mem = new_memory();
  dump(mem, HEX);

  char *b = "mem-sec";
  write(
    mem,
    b,
    sizeof(b),
    (size_t) 1010
  );

  struct file *f = new_file("testfile.txt");
  write_file(mem, f, 10);

  dump(mem, HEX);

  return 0;
}
