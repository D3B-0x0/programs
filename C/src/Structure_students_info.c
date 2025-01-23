#include<stdio.h>
typedef struct Structure_students{
  char name[30],dept[30],sub[30];
  int marks;
}stu_info;
void main(){
  stu_info x[4];
  int i;
  for(i=0;i<4;i++)
  {
    printf("Enter the details of the %d student\n",i+1);
    scanf("%s%s%s%d",x[i].name,x[i].dept,x[i].sub,&x[i].marks);
  }
  for(i=0;i<4;i++)
  {
    printf("\n Value of %d student name %s Department %s subject %s Marks %d",i+1,x[i].name,x[i].dept,x[i].sub,x[i].marks);
    printf("\n");
  }
}
