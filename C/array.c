#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

inline int found(int N, char name[], int number[], char *arr[]);

inline int found(int N, char name[], int number[], char *arr[]) {
    for(int i = 0; i != N; ++i) {
        if (strcmp(arr[i], name) == 0) {
            printf("%s=%d\n",name, number[i]);
            return 0;
        }
    }
    printf("%s", "Not found\n");
    return 1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    scanf("%d", &N);
    char *name_arr[N];
    int number_arr[N];
    for(int i = 0; i != N; ++i) {
        int number = 0;
        name_arr[i] = (char *)malloc(25);
        scanf("%s", name_arr[i]);
        scanf("%d", &number);
        number_arr[i] = number;
    }

    for(int i = 0; i != N; ++i) {
        char n[25];
        scanf("%s", n);
        found(N, n, number_arr, name_arr);
    }
    return 0;
}
