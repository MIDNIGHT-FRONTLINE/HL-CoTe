#include <stdio.h>

int main() {
	int num;

	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		for (int j = num-i; j > 0; j--){
            printf(" ");
        }
		for (int n = 2 * i - 1; n > 0; n--){
            printf("*");
        }
		printf("\n");
	}

	for (int i = num - 1; i > 0; i--) {
		for (int j = num - i; j > 0; j--){
            printf(" ");
        }
		for (int n = 2 * i - 1; n > 0; n--){
            printf("*");
        }
		printf("\n");
	}
	return 0;
}