#include<stdio.h>
void TOH(int n,char a,char b,char c);
int main()
{
  int n=3;
  TOH(n,'a','b','c');
  return 0;
}
void TOH (int n,char a, char b,char c)
{
  if (n==1)
  printf("disk %d moved from %c to %c\n",n,a,c);
  else
  {
    TOH(n-1,a,c,b);
    printf("disk %d moved from %c to %c\n",n,a,c);
    TOH(n-1,b,a,c);
  }
  
}
