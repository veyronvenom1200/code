#include <stdlib.h>
#include <stdio.h>

int *vector(int *arr, int *size);
void print(int *arr, int *size);

int *vector(int *arr, int *size) {

    int *temp;
    temp = malloc(sizeof(int) * *size);

    for (int i = 0; i < *size; ++i) {
        temp[i] = arr[i];
    }

    arr = realloc(arr, *size + 1);

    for (int j = 0; j < *size + 1; ++j) {
        if (j > (*size - 1)) {
            temp[j] = 0;
        }
        arr[j] = temp[j];
    }

    *size += 1;

    free(temp);
    return arr;
}

void print(int *arr, int *size) {
    for (int i = 0; i < *size + 1; ++i) {
        printf("%d\n", arr[i]);
    }
}

int main(void)
{
    int size = 10;
    int *arr;
    arr = malloc(sizeof(int) * size);
    for (int a = 0; a < 10; ++a) {
        arr[a] = a;
    }

    vector(arr, &size);
    // for (int i = 0; i < size + 1; ++i) {
    //     printf("%d\n", arr[i]);
    // }

    print(arr, &size);

}
