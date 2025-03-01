#include <stdio.h>

int main()
{
  int num1,num2,num3;

  printf("Enter first num : ");
  scanf("%d",&num1);
  printf("Enter second num : ");
  scanf("%d",&num2);
  printf("Enter three num : ");
  scanf("%d",&num3);

(num1 + num2 > num3 && num1 + num3 > num2 && num2 + num3 > num1) 
    ? printf("Yeah, a valid triangle can be formed \n") 
    : printf("No, a valid triangle cannot form \n");


 

  printf("\n");
  return 0;
}
