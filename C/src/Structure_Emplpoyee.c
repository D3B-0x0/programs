#include <stdio.h>
typedef struct employee{
    int sal,id;
    char nm[50];
}emp;

int main(){
    emp x[2];
    int i;
    for(i=0;i<2;i++){
        printf("Enter the details of Employee\n ");
        scanf("%s%d%d",x[i].nm,&x[i].id,&x[i].sal);
    }
    for(i=0;i<2;i++)
    {
        printf("name %s id %d  salary %d\n",x[i].nm,x[i].id,x[i].sal);
        printf("\n");
    }
    return 0;
}
