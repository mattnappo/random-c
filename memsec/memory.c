#include "memory.h"

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
   printf("f->s + offset: %lu\nmem->s: %lu\n", (f->s + offset), mem->s);
   printf("buffer is too big.\n");
    return 1;
  }
  for (size_t i = 0; i < f->s; i++) {
    mem->bytes[i + offset] = f->bytes[i];
  }
  return 0;
}

