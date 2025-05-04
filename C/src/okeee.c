#include <stdio.h>

int main() {
  int num;
  printf("Enter the number to check whether its divisible by 97 or not: ");
  scanf("%d",&num);

  while (num != 0) {
    if (num % 97 == 0) {
      printf("yes the num is divisible\n");
    } else {
      printf("The num is not divisible try again with diff number\n");
    }
  }
  return 0;
}
