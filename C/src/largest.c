#include "stdio.h"

int main () {
  int a,b,c;

  printf("Enter 3 numbers: ");
  scanf("%d %d %d",&a,&b,&c);

  if (a >= b && a >= c ) {
    printf("A (%d) is the biggest num \n",a);
  }
  else if (b >= a && b >= c) {
    printf("B (%d) is the biggest num \n",b);
  }
  else {
    printf("C (%d) is the biggest num \n",c);
  }

  return 0;
}

/*
 *SAME PROGRAM BUT SMALLEST NUM AMONG 3
 * #include "stdio.h"

int main () {
  int a,b,c;

  printf("Enter 3 numbers: ");
  scanf("%d %d %d",&a,&b,&c);

  if (a <= b && a <= c ) {
    printf("A (%d) is the smallest num \n",a);
  }
  else if (b <= a && b <= c) {
    printf("B (%d) is the smallest num \n",b);
  }
  else {
    printf("C (%d) is the smallest num \n",c);
  }

  return 0;
}
*/
