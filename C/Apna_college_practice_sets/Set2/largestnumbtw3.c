#include <stdio.h>

int main() {
  int num1, num2, num3, largest;

  printf("Enter the first number: ");
  scanf("%d", &num1);

  printf("Enter the second number: ");
  scanf("%d", &num2);

  printf("Enter the third number: ");
  scanf("%d", &num3);

  // Assume num1 is largest initially
  largest = num1;

  // Check if num2 is larger
  if (num2 > largest) {
    largest = num2;
  }

  // Check if num3 is larger
  if (num3 > largest) {
    largest = num3;
  }

  printf("%d is the largest\n", largest);

  return 0;
}
