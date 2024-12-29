#include <stdio.h>
#include <stdlib.h>

void trickyFunction(int *ptr, int val) {
    ptr = val;
}

int main() {
    int x = 10, y = 20;
    int *p = &x;

    printf("Before: x = %d, y = %d, p = %d\n", x, y,p);

    trickyFunction(&p, &y);

    printf("After: x = %d, y = %d, p = %d\n", x, y,p);

    return 0;
}