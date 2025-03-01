#include<stdio.h>
typedef struct Structure_students{
  char name[30],dept[30],sub[30];
  int marks;
}stu_info;
void main(){
  stu_info x[2];
  int i,w,q;
  for(i=0;i<2;i++)
  {
    printf("Enter the details of the %d student\n",i+1);
    scanf("%s%s%s%d",x[i].name,x[i].dept,x[i].sub,&x[i].marks);
  }
  w=x[0].marks;
  q=0;
  for(i=1;i<2;i++){
    if(w<x[i].marks){
      w=x[i].marks;
      q=i;
    }
  }
  printf(x[q].name);
  printf("\n");
}