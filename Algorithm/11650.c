#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
} PLANE;

int compare(const void *a, const void *b);

int main()
{
    int n;
    scanf("%d", &n);
    PLANE arr[n];
    
    for (int i = 0; i < n; i++){
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }

    qsort(arr, n, sizeof(PLANE), compare);
    for (int i = 0; i < n; i++){
        printf("%d %d\n", arr[i].x, arr[i].y);
    }
}

int compare(const void *a, const void *b){
    PLANE A = *(PLANE *)a;
    PLANE B = *(PLANE *)b;

    if (A.x > B.x)
        return 1;
    else if (A.x == B.x)
    {
        if (A.y > B.y)
            return 1;
        else
            return -1;
    }
    return -1;
}