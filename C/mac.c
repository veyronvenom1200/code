#include <stdio.h>
#import <stdlib.h>

#define MAX 15

// #define MULT(a, b) a*b

struct bit {
    unsigned int a: 1;
    unsigned int b: 2;
    unsigned int : 1;
    unsigned short c: 1;
};

int main() {
   //  FILE *fp;

   //  char str[100], pr[100];

   //  scanf("%s", str);

   //  fp = fopen("file.txt", "r+");
   //  fputs(str, fp);

   //  if( fgets (pr, 100, fp)!=NULL ) {
   //    /* writing content to stdout */
   //    puts(pr);
   // }
   // fclose(fp);

   //  return 0;

    // scanf("%[^\n]%*c", sen);
    char buf[MAX]; 
    fgets(buf, MAX, stdin); 
    printf("string is: %s\n", buf); 
  
    return 0; 
}
