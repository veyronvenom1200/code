#include <stdio.h>

int *left_rotation(int d, int *a) {
    int i = 0;
    int save = a[0];
    while (i < (d -1)) {
        a[i] = a[i + 1];
        ++i;
    }
    a[i] = save;

    return a;
}

int main() {
    int d, n, i = 0;
    scanf("%d %d", &d, &n);
    int a[d];
    for (; i < d; ++i) {
        scanf("%d", (a + i));
    }

    i = 0;
    while (i < n) {
        left_rotation(d, a);
        ++i;
    }
    for (int j = 0; j < d; ++j) {
        printf("%d ", a[j]);
    }
}
