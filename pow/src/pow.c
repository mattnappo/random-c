#include "include.h"
#include "core.h"
#include "common.h"

int main() {
    // generate_thread(NULL);
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, generate_thread, NULL);
        pthread_join(thread_id, NULL);
        exit(0);
    }
    
}