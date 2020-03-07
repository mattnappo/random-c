#include <stdlib.h>
#include <stdio.h>

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
        f->bytes = malloc(sizeof(char) * (fsize + 1));
        f->s = fsize;

        rewind(fp);
        read_size = fread(f->bytes, sizeof(char), fsize, fp);

        f->bytes[fsize] = '\0';

        if (fsize != read_size) {
            free(f->bytes);
            f->bytes = NULL;
            f->s = 0;
        }
        fclose(fp);
    }

    return f;
}

int main()
{
    struct file *fprime = new_file("test");
    printf("%s", fprime->bytes);
    return 0;
}