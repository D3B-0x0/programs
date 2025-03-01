//49:28 vid timestamp

#include <stdio.h>
//#include <math.h>

int main()
{
  int num1,num2,num3;

  printf("Enter first num :\n");
  scanf("%d",&num1);
  printf("Enter second num :\n");
  scanf("%d",&num2);
  printf("Enter three num :\n");
  scanf("%d",&num3);

 
  if (num1+num2 > num3 && num1+num3 > num2 && num2+num3 > num1 ) 
  {
    printf("Yeah a valid triangle can be formed \n");
  }
  else {
    printf("No a valid triangle cannot form \n");
  }


 

  printf("\n");
  return 0;
}
