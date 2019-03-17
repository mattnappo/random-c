#include <stdio.h>

enum style {
    UNDERLINED,
    BOLD,
    ITALIC
};

int main() {
    enum style someFontStyle;
    someFontStyle = UNDERLINED;

    printf("font type: %d", someFontStyle);

    return 0;
}