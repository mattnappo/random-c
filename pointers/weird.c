#include <stdio.h>
#include <stdlib.h>
#define LEN 100
int main(void) {
    int arr[LEN];
    int i;
    printf("&arr[LEN]: %p\n", &arr[LEN]);
    printf("&i:        %p\n", &i);
    return 0;
}
