#include <stdio.h>

int main () {

  int num;
  printf("Enter a number to check whether its odd or eve: ");
  scanf("%d",&num);

  if (num%2 == 0 ) {
    printf("Number is even \n");
  }
  else {
    printf("Number is odd\n");

    if (num == 0) {
      printf("Dont input 0\n");
    } 

  }
}
