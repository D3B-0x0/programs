#include <stdio.h>

int main() {
    FILE *f;
    f=fopen("/home/ghost/Documents/programs/C/src/Test.txt","r");
    char c;
    int a=0;
    while((c=fgetc(f))!=EOF){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
              a=a+1;    
        }

      
    }
    printf("%d",a);
    printf("\n");
    fclose(f);
    return 0;
}