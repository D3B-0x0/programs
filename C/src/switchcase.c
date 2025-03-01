#include <stdio.h>

int main(){ 

  int l,b,x;

  printf("Enter the length \n");
  printf("Enter the breadth \n");
  scanf("%d%d",&l,&b);
  printf("For Area Enter 1 \n");
  printf("For Perimeter Enter 2 \n");
  scanf("%d",&x);

  switch (x) {
    case 1:
      printf("Area of rectangle is= %d",l*b);
      break;
    case 2:
      printf("Perimeter of rectangle is= %d",2*(l+b));
      break;

    default:
      printf("wrong infoo \n");
  }
  return 0;
}




























