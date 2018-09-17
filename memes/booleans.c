#include <stdio.h>
#include <stdlib.h>

typedef struct m_byte {
    int b0;
    int b1;
    int b2;
    int b3;

    int b4;
    int b5;
    int b6;
    int b7;
    
};

char *get_char(int bit) {
    char *buffer = "";
    sprintf(buffer, "%d", bit);
    printf("%s", buffer);
    return buffer;
}

char *get_chars() {
    char *final = "";

    
    
    return final;
}


int main(void) {
    char *data = "01010110";
    char c = strtol(data, 0, 2);
    printf("%s = %c\n", data, c);
    return 0;
}