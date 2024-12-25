#include<stdio.h>

typedef struct student{
  char name[30];
  int marks;
}stu;

void main()
{
  stu x,y;
  printf("Enter the 1st students details\n");
  scanf("%s",&x.name);
  scanf("%d",&x.marks);

  printf("Enter the 2nd students details\n");
  scanf("%s",&y.name);
  scanf("%d",&y.marks);

  printf("\n Value of 1st student name %s Marks %d",x.name,x.marks);
  printf("\n Value of 2nd student name %s Marks %d",y.name,y.marks);

  printf("\n");

}
