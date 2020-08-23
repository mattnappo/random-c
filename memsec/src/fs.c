#include "fs.h"

struct file *new_file(const char *name)
{
    struct file *f = malloc(sizeof(struct file));
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
  
    return f;
}

struct fs *new_fs() // TODO: size parameter
{
    struct fs *fs = malloc(sizeof(struct fs));
    fs->mem = malloc(sizeof(struct memory));
    fs->mem = new_memory();
    fs->ft = new_ftable();

    return fs;
}

int add_file(struct fs *fs, struct file *f, size_t offset)
{
    // Write the bytes to the memory at the right location
    write(fs->mem, f->bytes, f->s, offset);

    // Add the file metadata to the ftable
    struct ftable_entry *entry = malloc(sizeof(struct ftable_entry));
    strcpy(entry->name, f->name);
	entry->s = f->s;
	entry->offset = offset;

    add_ftable_entry(fs->ft, entry);
    return 0;
}

int remove_file();

struct ftable *new_ftable()
{
    struct ftable *ft = malloc(sizeof(struct ftable));
    for (int i = 0; i < MAX_FILES; i++) {
        ft->files[i] = malloc(sizeof(struct ftable_entry));
    }
    ft->f_count = 0;
    return ft;
}

int add_ftable_entry(struct ftable *ft, struct ftable_entry *entry)
{
    if (ft->f_count + 1 > MAX_FILES)
	return -1;

    ft->files[ft->f_count] = entry;
    ft->f_count++;

    return 0;
}

int print_ftable(struct ftable *ft)
{
    for (int i = 0; i < ft->f_count; i++) {
        printf("file %2d:\n  name: %s\n  offset, size: (%ld, %ld)\n\n",
            i,
            ft->files[i]->name,
            ft->files[i]->offset,
            ft->files[i]->s
        );
    }

    return 0;
}
