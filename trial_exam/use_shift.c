#include <stdio.h>

void sort(int arr[], int n);

void rotate(int arr[], int n, int k);

int main(){
    int N, K;

    printf("N: ");
    scanf("%d", &N);

    printf("K: ");
    scanf("%d", &K);

    int arr[N];

    for(int i = 0; i < N; i++){
        printf("(%d / %d): ", i + 1, N);
        scanf("%d", &arr[i]);
    }

    sort(arr, N);

    printf("초기 배열: [");
    for (int i = 0; i < N; i++){
        if (i == N - 1){
            printf("%d", arr[i]);
        }
        else{
            printf("%d, ", arr[i]);
        }
    }
    printf("], K = %d\n\n", K);

    rotate(arr, N, K);

    printf("회전 후: [");
    for (int i = 0; i < N; i++){
        if (i == N - 1){
            printf("%d", arr[i]);
        }
        else{
            printf("%d, ", arr[i]);
        }
    }
    printf("]\n");

    return 0;
}

void sort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1; j++){
            if (arr[j] > arr[j + 1]){
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

void rotate(int arr[], int n, int k){
    k = k % n;

    for (int i = 0; i < k; i++){
        int t = arr[n - 1];
        for (int j = n - 1; j > 0; j--){
            arr[j] = arr[j - 1];
        }
        arr[0] = t;
    }

    // for (int i = 0; i < n; i++){
    //     int t = arr[i];
    //     arr[i] = arr[n - i - 1];
    //     arr[n - i - 1] = t;
    // }

    // for (int i = 0; i < k / 2; i++){
    //     int t = arr[i];
    //     arr[i] = arr[k - i - 1];
    //     arr[k - i - 1] = t;
    // }

    // for (int i = k; i < (n + k) / 2; i++){
    //     int t = arr[i];
    //     arr[i] = arr[n - i + k - 1];
    //     arr[n - i + k - 1] = t;
    // }

}