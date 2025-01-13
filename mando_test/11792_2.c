#include <stdio.h>
#include <math.h>

typedef struct {
    int disk;
    int start;
    int middle;
    int end;
    int state;
} Task;

void hanoiIterative(int n);

int main()
{
    int n;
    scanf("%d", &n);

    printf("%d\n", (1 << n) - 1);
    hanoiIterative(n);

    return 0;
}

void hanoiIterative(int n)
{
    Task stack[1024];
    int top = -1;

    stack[++top] = (Task){n, 1, 2, 3, 0};

    while (top >= 0)
    {
        Task *current = &stack[top];

        if (current->disk == 1)
        {
            printf("%d %d\n", current->start, current->end);
            top--;
        }
        else if (current->state == 0)
        {
            current->state = 1;
            stack[++top] = (Task){current->disk - 1, current->start, current->end, current->middle, 0};
        }
        else if (current->state == 1)
        {
            printf("%d %d\n", current->start, current->end);
            current->state = 2;
        }
        else if (current->state == 2)
        {
            stack[++top] = (Task){current->disk - 1, current->middle, current->start, current->end, 0};
            current->state = 3;
        }
        else
        {
            top--;
        }
    }
}