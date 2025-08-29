// Check if a character is a digit (0-9)
#include <stdio.h>

int isDigit(char ch) {
  return ch >= '0' && ch <= '9';
}

int main() {
  char ch;
  printf("Enter a char to check: ");
  scanf("%c", &ch);

  if (isDigit(ch))
    printf("It's a digit.\n");
  else
    printf("It's not a digit.\n");

  return 0;
}
