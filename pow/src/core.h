#ifndef CORE_H
#define CORE_H

int check_is_valid(const char *hash);
char *generate();

void *generate_thread(void *vargp);

#endif