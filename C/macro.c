#include <stdio.h>
#import <stdlib.h>
#define N_ARRAY(a) sizeof(a)/sizeof(a[0])


void printMat(int *a, unsigned long size) {
   int count = 0;
   for (; count <= size; ++count) {
      if ((count % 4 != 3) || (count == 0)) {
         printf("%d ", a[count]);
      } else {
         printf("%d \n", a[count]);
      }
   }
}

int *matrixAdd(int *a, int *b, unsigned long size) {
   int *c = (int *)malloc(7 * sizeof(int));
   int count = 0;
   for (; count <= size; ++count) {
      c[count] = a[count] + b[count];
   }
   free(c);
   return c;
}

int main() {
   int a[7];
   int b[7];
   unsigned int x = ~0;
   int d = 0;
   for (; d < 8; ++d) {
      a[d] = d;
      b[d] = d + 10;
   }


   printMat(matrixAdd(a, b, N_ARRAY(a)), N_ARRAY(a));
   printf("%u", 114 ^ 170);
}
