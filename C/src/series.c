#include <stdio.h>

#define MAX 10
int TOP = -1;
int st[MAX];
void PUSH() {
  int k;
  if (TOP == MAX - 1) {
    printf("QUEUE IS FULL");
  } else {
    printf("\n Enter value");
    scanf("%d", &k);
    st[++TOP] = k;
    printf("\n value pushed");
  }
}
void POP() {
  int k;
  if (TOP == ){
    printf("STACK IS EMPTY");
  } else {
    k = st[TOP];
    st[TOP] = 0;
    TOP--;
    printf("\n %d is popped", k);
  }
}
void display() {
  int i;
  if (TOP == -1) {
    printf("STACK IS EMPTY");
  } else {
    printf("\n Top value is %d \n", st[TOP]);
    for (i = TOP; i >= 0; i--) {
      printf(" %d -> ", st[i]);
    }
  }
}
int main() {
  int x;
  while (1) {
    printf("\n 1-PUSH 2-POP 3-DISPLAY 0-EXIT\n ");
    scanf("%d", &x);
    if (x == 0) {
      printf("\n Thank You ");
      break;
    }
    switch (x) {
    case 1:
      PUSH();
      break;
    case 2:
      POP();
      break;
    case 3:
      display();
      break;
    default:
      printf("\n Wrong entry Try again ");
    }
  }
  return 0;
}
