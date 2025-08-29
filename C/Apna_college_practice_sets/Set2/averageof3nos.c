#include <stdio.h>

int main() {
  double num1,num2,num3;
  printf("Welcome to the program of printing average of 3 numbers:D\n");

  printf("Enter a num: ");
  scanf("%lf",&num1);
  printf("Enter 2nd num: ");
  scanf("%lf",&num2);
  printf("Enter 3rd num: ");
  scanf("%lf",&num3);

  printf("The average of the numbers are: %.2lf \n",(num1+num2+num3/3));
  return 0;
}
