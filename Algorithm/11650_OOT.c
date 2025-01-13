#include <stdio.h>

int main()
{
    int n, i, j;
    scanf("%d", &n);
    int x[n], y[n];
    i = 0;
    while(i < n)
    {
        scanf("%d %d", &x[i], &y[i]);
        i++;
    }
    i = 0;
    while(i < n - 1)
    {
        j = i + 1;
        while(j < n)
        {
            if(x[i] >= x[j] && y[i] >= y[j])
            {
                int temp;
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
                temp = y[i];
                y[i] = y[j];
                y[j] = temp;
            }
            j++;
        }
        i++;
    }
    i = 0;
    while(i < n)
    {
        printf("%d %d\n",x[i], y[i]);
        i++;
    }
}