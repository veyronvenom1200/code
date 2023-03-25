#include <stdio.h>

int main() {
    int arr[] = {3,2,5,1,3,4,5,23,2};
    //printf("%lu", sizeof(arr)/sizeof(arr[0]));
    for (int cnt = 0; cnt < sizeof(arr)/sizeof(arr[0]); ++cnt) {
        for (int i = 0; i != sizeof(arr)/sizeof(arr[0]); ++i) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
            }
        }
    }

    int i = 0;
    for (; i < sizeof(arr)/sizeof(arr[0]); ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}
