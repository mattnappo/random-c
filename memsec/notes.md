# Some random notes

The `memory` struct does not need any methods other than read and write.

# Todo:
 * implement ftable
 * start with the `fs::add_file` method, adding the ftable code.
 * `fs::new_fs` might also need ftable initialization code.

# The memory and the ftable are completely discrete structures
 * `memory` is like the backend, and the ftable is just the frontend. They should be kept as separate elements.
