#include <stdio.h>

int main() 
{
  FILE *f1;
  char c;
  //printf("home/deb/Documents/CODING/C/src/disco-op.txt");
  f1=fopen("/home/ghost/Documents/programs/C/src/test.txt","w");
  while((c=getchar())!=EOF)
  {
    putc(c,f1);
    fclose;
  }
  fclose(f1);
  return 0; 
}
