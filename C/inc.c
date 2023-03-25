#include <stdio.h>

int main() {
    int arr[10] = {1, 4, 2, 5, 3, 10, 20, 15, 14, 6};
    for(int i = 2; i < 10; ++i) {
        while(arr[i] < arr[i - 1]) {
            int temp = arr[i - 1];
            arr[i -1] = arr[i];
            arr[i] = temp;
            --i;
        }
    }

    for(int j = 0; j < 10; ++j) {
        printf("%d\n", arr[j]);
    }
}
