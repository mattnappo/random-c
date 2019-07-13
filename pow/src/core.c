#include "include.h"
#include "common.h"

int check_is_valid(const char *hash) {
    for (int i = 0; i < DIFFICULTY; i++) {
        if (hash[i] != 0x30) {
            return 0;
        }
    }
    return 1;
}

char *generate() {
    unsigned long random_bytes = generate_random_bytes();
    unsigned long hashed_bytes = hash(
        unsigned_long_tostring(random_bytes)
    );

    char *hex = (char *) malloc(BUFF_SIZE * sizeof(char));
    sprintf(hex, "%lx", hashed_bytes);
    printf("[hex] %s\n", hex);
    return hex;
}

void *generate_thread(void *vargp) {
    sleep(1);
    char *valid_hex;

    while (1) {
        char *g_hex = generate();
        if (check_is_valid(g_hex)) {
            valid_hex = g_hex;
            printf("[valid] %s\n", g_hex);
            break;
        }
    }
    
    write_to_file("success", valid_hex);
}