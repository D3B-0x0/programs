#include <stdio.h>
#include <malloc.h>
int main() {
    int *p,n,x,*t,i;
    printf("Enter how many");
    scanf("%d",&x);
    p=(int *) malloc (sizeof(int)*x);
    t=p;
    for(i=1;i<=x;i++){
        scanf("%d",&*p);
        p++;
    }
p=t;
for(i=1;i<=x;i++){
    printf("%d",&*p);
    p++;
}
for(i=1;i<=x;i++){
    *p=*p+5;
    p++;
}

    // Your code here
    return 0;
}
