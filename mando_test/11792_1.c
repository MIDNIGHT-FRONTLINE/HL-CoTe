#include <stdio.h>

void move(int start, int end);
void hanoi(int n, int start, int middle, int end);

int main()
{
    int n;
    scanf("%d", &n);

    printf("%d\n", (1 << n) - 1);
    hanoi(n, 1, 2, 3);

    return 0;
}

void move(int start, int end)
{
    printf("%d %d\n", start, end);
}

void hanoi(int n, int start, int middle, int end)
{
    if (n > 0)
    {
        hanoi(n - 1, start, end, middle);
        move(start, end);
        hanoi(n - 1, middle, start, end);
    }
}