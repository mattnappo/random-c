#include "fs.h"

int main()
{
	struct fs *tfs = new_fs(); // Make the fs
	struct file *tfile = new_file("testfile.txt"); // Make a new file

	int status;
	status = add_file(tfs, tfile, 0);
	status = dump(tfs->mem, ASCII);

	return status;
}

