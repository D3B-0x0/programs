 #include<stdio.h>

void natty(int x) {
   if (x == 0)
       return; // End recursion
   printf("%d \n", x);
   natty(x - 1);
}

void nat(int x) {
   if (x > 0) {
       printf("%d \t", x);
       nat(x - 1);
   }
}

int main() {
   int n;
   printf("Enter the number: ");
   scanf("%d", &n);
   printf("\n");
   nat(n);
   printf("\n");
   return 0;
}
  

