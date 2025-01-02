#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int swap(int* a, int* b);

int main(void)
{
    int line[100];
	int num1, num2;

	scanf("%d", &num2);

	for (int i = 0; i < num2; i++)
	{
		line[i] = i + 1;
		scanf("%d", &num1);

		for (int j = i; j > i - num1; j--)
			swap(&line[j], &line[j - 1]);


	}

	for (int i = 0; i < num2; i++)
	{
		printf("%d ", line[i]);
	}

	return 0;
}

int swap(int* x, int* y)
{
	int temp;
    
	temp = *x;
	*x = *y;
	*y = temp;
}