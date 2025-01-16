#include <stdio.h>
#include <stdlib.h>

int arr[500001];
int count[8001];

int compare(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

int main() {
    int n, sum = 0, max_count = 0, mode = 0, flag = 0, range;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        count[arr[i] + 4000]++;
    }

    for (int i = 0; i < 8001; i++) {
        if (count[i] > max_count) {
            max_count = count[i];
            mode = i - 4000;
            flag = 1;
        } else if (count[i] == max_count) {
            if (flag == 1) {
                mode = i - 4000;
                flag = 0;
            }
        }
    }

    qsort(arr, n, sizeof(int), compare);

    range = arr[n - 1] - arr[0];

    printf("%.0f\n", (double)sum / n);
    printf("%d\n", arr[n / 2]);
    printf("%d\n", mode);
    printf("%d\n", range);

    return 0;
}