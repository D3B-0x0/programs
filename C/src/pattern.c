#include <stdio.h>

int main() {
    int n,x,s;
    printf("Enter ");
    scanf("%d",&n);
    int k=65;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf(" %d ",k);
        }
        printf("\n");
        k++;
    }
    return 0;
}
