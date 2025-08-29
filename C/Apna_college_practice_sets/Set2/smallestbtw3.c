#include <stdio.h>

int main() {
  int num1, num2, num3, smallest;

  printf("Enter the first number: ");
  scanf("%d", &num1);

  printf("Enter the second number: ");
  scanf("%d", &num2);

  printf("Enter the third number: ");
  scanf("%d", &num3);

  // Assume num1 is smallest initially
  smallest = num1;

  // Check if num2 is smaller
  if (num2 < smallest) {
    smallest = num2;
  }

  // Check if num3 is smaller
  if (num3 < smallest) {
    smallest = num3;
  }

  printf("%d is the smallest\n", smallest);

  return 0;
}
