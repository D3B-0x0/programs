#include <stdio.h>

//Taking the variables.
int main () {
  int a,b,c;
  float avg;

  //taking user input for 3 nums.  
  printf("Enter 3 numbers: ");
  scanf("%d %d %d",&a,&b,&c);

  //performing operations and finding average.  
  printf("The average of three numbers (%d) (%d) (%d) are %lf \n",a,b,c,(a+b+c/3.0));

  return 0;
}
