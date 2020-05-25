#include "memory.h"

int test_new_file()
{
  struct memory *mem = new_memory();

  char *b = "mem-sec";
  write(
    mem,
    b,
    sizeof(b),
    (size_t) 1010
  );

  struct file *f = new_file("testfile.txt"); write_file(mem, f, 10);

  dump(mem, HEX);
  return 0;
}

int main()
{
  struct file *f = new_file("test");
  struct memory *m = new_memory();
  dump(m, DEC);
  for (int i = 0; i < 30; i++) {
      printf("%d [%x]", i, m->bytes[i]);
  }
  printf("\n");

  write_file(m, f, 0);

  for (int i = 0; i < 30; i++) {
      printf("%d [%c]", i, m->bytes[i]);
  }
  printf("\n");
  dump(m, DEC);
  return 0;
}

