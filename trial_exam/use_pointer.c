#include <stdio.h>

void find(int arr[], int *min, int *max, int size);

int main(){
    int arr[5];
    int min, max;

    // for(int i = 0; i < sizeof(arr); i++){
    //     scanf("%d", &arr[i]);
    // }
    scanf("%d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);

    find(arr, &min, &max, sizeof(arr) / sizeof(arr[0]));

    printf("min = %d\n", min);
    printf("max = %d\n", max);

    return 0;
}

void find(int arr[], int *min, int *max, int size){
    *min = arr[0];
    *max = arr[0];

    for(int i = 0; i < size; i++){
        if(arr[i] < *min){
            *min = arr[i];
        }
        else if(arr[i] > *max){
            *max = arr[i];
        }
    }
}