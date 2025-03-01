#include <stdio.h>

int is_digit(char ch) {
    return (ch >= '0' && ch <= '9');  // Check ASCII range for digits
}

int main() {
    char ch = ' '; // Change this to test different characters

    if (is_digit(ch))
        printf("%c is a digit.\n", ch);
    else
        printf("%c is NOT a digit.\n", ch);

    return 0;
}

