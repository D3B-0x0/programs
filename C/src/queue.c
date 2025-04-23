#include <stdio.h>
#define MAX 10

int F = -1, R = -1;
int Q[MAX];
void Enque() {
  int k;
  if (R == MAX - 1) {
    printf("QUEUE IS FULL");
  } else {
    printf("\n Enter value");
    scanf("%d", &k);
    if (F == -1) {
      F++;
      R++;
    } else {
      R++;
    }
    Q[R] = k;
    printf("\n value pushed");
  }
}
void Deque() {
  int k;
  if (F == -1) {
    printf("Queue is IS EMPTY");
  } else {
    k = F;
    F++;
    printf("\n %d is popped", k);
  }
}
void display() {
  int i;
  if (F == -1) {
    printf("STACK IS EMPTY");
  } else {
    printf("\n Top value is %d \n", F);
    for (i = F; i <= R; i++) {
      printf(" %d -> ", Q[i]);
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
        Enque();
        break;
      case 2:
        Deque();
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
