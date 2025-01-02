#include <stdio.h>
#include <string.h>
#define MAX_NUM 10001

int size = -1;
int stack[MAX_NUM];

void push(int x);
int empty();
int pop();
int top();

int main()
{
	int N = 0, push_data = 0;
	char command[5] = {0, };

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{

		scanf("%s", command);

		if (!strcmp(command, "push"))
		{
			scanf("%d", &push_data);
			push(push_data);
		}
		else if (!strcmp(command, "pop"))
		{
			printf("%d\n", pop());
		}
		else if (!strcmp(command, "empty"))
		{
			printf("%d\n", empty());
		}
		else if (!strcmp(command, "size"))
		{
			printf("%d\n", size + 1);
		}
		else if (!strcmp(command, "top"))
		{
			printf("%d\n", top());
		}
	}

	return 0;
}

void push(int x)
{
	size++;
	stack[size] = x;
}
int empty()
{
	if (size == -1){
        return 1;
    }
	else{
		return 0;
    }
}
int pop()
{
	if (empty()){
		return -1;
	}
	else{
		return stack[size--];
	}
}
int top()
{
	if (empty()){
        return -1;
    }
	else{
        return stack[size];
    }
}