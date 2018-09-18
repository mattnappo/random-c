#include <stdio.h>
#include <stdlib.h>

struct m_byte {
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

char *get_chars(struct m_byte) {
    char *b0 = get_char(m_byte.b0);
    char *b1 = get_char(m_byte.b1);
    char *b2 = get_char(m_byte.b2);
    char *b3 = get_char(m_byte.b3);
    char *b4 = get_char(m_byte.b4);
    char *b5 = get_char(m_byte.b5);
    char *b6 = get_char(m_byte.b6);
    char *b7 = get_char(m_byte.b7);
    
    char *final = ;
    return final;
}


int main(void) {
    char *data = "01010110";
    char c = strtol(data, 0, 2);
    printf("%s = %c\n", data, c);
    return 0;
}