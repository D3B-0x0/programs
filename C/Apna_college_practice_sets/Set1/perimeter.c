#include <stdio.h>

int main() {
  int length,width;
  printf("Enter the length of the rectangle: ");
  scanf("%d",&length);
  printf("Enter the width of the rectangle: ");
  scanf("%d",&width);
  printf("The perimeter of the rectangle is: %d \n",(2*(length+width)));

  return 0;
}
