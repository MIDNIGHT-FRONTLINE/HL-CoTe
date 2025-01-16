#include<stdio.h>

int num = 0; 
int word[1000] = {0};
int tmp = 0;

int main() {
	scanf("%d", &num);
	
	for (int i = 0; i < num; i++) {
		scanf("%d", &word[i]);
	}
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num-1; j++) {
			if (word[j + 1] < word[j]) {
				tmp = word[j + 1];
				word[j + 1] = word[j];
				word[j] = tmp;
			}
		}
	}
	for (int i = 0; i < num; i++) {
		printf("%d\n", word[i]);
	}
	return 0;
}