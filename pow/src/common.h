#ifndef COMMON_H
#define COMMON_H

unsigned long generate_random_bytes();  // Generate random bytes
unsigned long hash(unsigned char *str); // Hash a string

char *unsigned_long_tostring(unsigned long ul); // Convert an unsigned long to a string

int write_to_file(char *path, char* bytes); // Write data to a file

#endif