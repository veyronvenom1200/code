#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// #pragma pack(1)

void swap(int *a, int *b);

struct packing {
    int c;
    char b;
    char *d;
};

int main(int argc, char const *argv[])
{
    // FILE *fp, *fp_begin;
    // fp = fopen("test.txt", "r");
    // fp_begin = fp;
    // printf("%p\n", fp);

    // int i = 0;

    // if ((fp = fopen("test.txt", "r+")) == NULL) {
    //     printf("Error opening file\n");
    //     exit(1);
    // }

    // // get size of string from file
    // while(fgetc(fp) != EOF) {
    //     ++i;
    // }

    // fseek(fp, 0, SEEK_SET); // reset fp to beginning of file

    // char str[i];

    // fgets(str, 123, fp);

    // char *j = strcasestr(str, "hello");
    // if(strcasestr(str, "hello")) { // find string
    //     printf("success\n");
    // }

    // printf("Size of i: %d\n", i);
    // printf("%s\n", str);
    // printf("String address: %p\nSize of j: %lu\n", j, sizeof(j));
    // printf("%p\n%p\n", fp, fp_begin);

    // fp_begin += (j - (char *)fp_begin)/sizeof(char);

    // printf("fp_begin: %p\n", fp_begin);

    // fprintf(fp_begin, "yeeeeeeet\n");

    // // printf("%d\n", );
    // fclose(fp);

    struct packing p;

    printf("%lu\n", sizeof(p));


    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}