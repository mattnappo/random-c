#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void print_line_spaces(char *string, int spaces) {
    for (unsigned int i = 1; i <= spaces; i++) {
        printf(" ");
    }
    printf("%s", string);
}

void backwards_print_line_spaces(char *string, int spaces) {
    for (unsigned int i = 0; i <= spaces; i++) {
        printf(" ");
    }
    printf("%s", string);
}

void clear_screen() {
    system("clear");
}

void frame(int spaces) {
    print_line_spaces("         ,~~.     \n", spaces);
    print_line_spaces("        (  6 )-_, \n", spaces);
    print_line_spaces("   (\\___ )=='-'  \n", spaces);
    print_line_spaces("    \\ .   ) )    \n", spaces);
    print_line_spaces("     \\ `-' /     \n", spaces);
    print_line_spaces("~`'~`~`~`~`~`~`~'`~'`~'`~`~`~`~'`~`'~`'~'`~`~'`~`~'`~`~`~'`~`~'`~'`~`~'`~`~'`~\n", 0);
    print_line_spaces("~`~`~'`~`~`~`~`~'`~'`~'`~`~'`~`~`~`'~`'~`~'`~'`~`~'`~`~`~'`~`~'`~'`~`~'`~`~'`~\n", 0);
    print_line_spaces("~`'~`~`~`~`~`~`~'`~'`~'`~'`~`~`~'`~`'~`'~`~`~'`~`~'`~`~`~'`~`~'`~`~'`~`~`~'`~\n", 0);

    usleep(150 * 1000);
    clear_screen();
}

void backwards_frame(int spaces) {
    backwards_print_line_spaces("                        \n", spaces);
    backwards_print_line_spaces("                        \n", spaces);
    backwards_print_line_spaces("   _      _      _      \n", spaces);
    backwards_print_line_spaces(" >(.)__ <(.)__ =(.)__   \n", spaces);
    backwards_print_line_spaces("  (___/  (___/  (___/   \n", spaces);
    backwards_print_line_spaces("~`'~`~`~`~`~`~`~'`~'`~'`~`~`~`~'`~`'~`'~'`~`~'`~`~'`~`~`~'`~`~'`~'`~`~'`~`~'`~\n", 0);
    backwards_print_line_spaces("~`~`~'`~`~`~`~`~'`~'`~'`~`~'`~`~`~`'~`'~`~'`~'`~`~'`~`~`~'`~`~'`~'`~`~'`~`~'`~\n", 0);
    backwards_print_line_spaces("~`'~`~`~`~`~`~`~'`~'`~'`~'`~`~`~'`~`'~`'~`~`~'`~`~'`~`~`~'`~`~'`~`~'`~`~`~'`~\n", 0);

    usleep(125 * 1000);
    clear_screen();
}

int main() {
    clear_screen();
    while (1) {
        for (unsigned int i = 0; i < 66; i++) {
            frame(i);
        }

        for (unsigned int i = 66; i > 0; i--) {
            backwards_frame(i);
        }
    }
}