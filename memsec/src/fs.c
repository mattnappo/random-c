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

    for (int i = 0; i < strlen(name); i++) {
        f->name[i] = name[i];
    }
    f->offset = 0;
  
    return f;
}

struct fs *new_fs() // TODO: size parameter
{
    struct fs *fs = malloc(sizeof(struct fs *));
    fs->mem = malloc(sizeof(struct memory *));
    fs->mem = new_memory();

    return fs;
}

int add_file(struct fs *fs, struct file *f, size_t offset)
{
    // Add to the vector of files
    write(fs->mem, f->bytes, f->s, offset);
    return 0;
}

int remove_file();

struct f_table *new_f_table()
{
    struct f_table *ft = malloc(sizeof(struct f_table *));
    ft->f_count = 0;
    return ft;
}

int add_f_table_entry(struct f_table *ft, struct file *f)
{
    if (ft->f_count > MAX_FILES) return -1;

    ft->files[ft->f_count] = f; // malloc here?

    return 0;
}

