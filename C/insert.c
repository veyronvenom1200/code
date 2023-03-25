#include <stdio.h>

int main(void)
{
    int arr[7] = {1, 6, 3, 2, 6, 4, 1};

    for (int i = 1; i < 7; ++i) // loop invariance & initialization step (prior to loop in loops)
    {
        int a = arr[i];
        while(arr[i - 1] < a && i > 0) {
            arr[i]=arr[i -1];
            arr[i - 1] = a;
            i -= 1;
        }

        arr[i]= a;
    }

    for (int i = 0; i < 7; ++i)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}