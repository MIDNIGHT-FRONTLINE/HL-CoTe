#include <stdio.h>

int main(){
    int N, M;

    scanf("%d %d", &N, &M);

    if (N <= 2 || M <= 2){
        return 0;
    }

    int arr[N][M];
    int total = 0;
    int edge = 0;
    int in = 0;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            printf("arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
            total += arr[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if (i == 0 || i == N - 1 || j == 0 || j == M - 1){
                edge += arr[i][j];
            }
            else{
                in += arr[i][j];
            }
        }
    }

    printf("total: %d\n", total);
    printf("total_aver: %.2f\n", (float)total / (N * M));
    printf("edge: %d\n", edge);
    printf("inner: %d\n", in);

    return 0;
}