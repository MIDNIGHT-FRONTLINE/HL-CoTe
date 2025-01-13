#include <stdio.h>
#define MAX 100001

int n, m, map[MAX] = {0};
int q[(MAX * 2)] = {0};

int main()
{
    scanf("%d %d", &n, &m);
    if (n == m)
    {
        printf("0\n");
        return 0;
    }
    q[0] = n;
    int cur = 0, last = 1;
    while (cur < last && map[m] == 0)
    {
        int pos = q[cur++];
        if (pos - 1 >= 0 && map[pos - 1] == 0)
        {
            q[last++] = pos - 1;
            map[pos - 1] = map[pos] + 1;
        }
        if (pos + 1 < MAX && map[pos + 1] == 0)
        {
            q[last++] = pos + 1;
            map[pos + 1] = map[pos] + 1;
        }
        if (pos * 2 < MAX && map[pos * 2] == 0)
        {
            q[last++] = pos * 2;
            map[pos * 2] = map[pos] + 1;
        }
    }
    printf("%d\n", map[m]);
    return 0;
}