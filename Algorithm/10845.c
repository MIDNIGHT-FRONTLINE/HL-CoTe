#include <stdio.h>
#include <string.h>

#define True 1
#define False 0
#define MAX_LEN 100000 

typedef struct _cQueue{
    int size;
    int front; 
    int rear;
    int arr[MAX_LEN];
}CQUEUE;

typedef CQUEUE Queue;

int Empty(Queue *pq);
int Nextindex(int pos);
int Front(Queue *pq);
int Back(Queue *pq);
int Size(Queue *pq);
int Pop(Queue *pq);

void Queueinit(Queue *pq);
void Push(Queue *pq,int data);

int main(void){
    Queue q;

    Queueinit(&q);

    char array[6];
    int n;

    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        scanf("%s", array);

        if(strcmp(array, "push") == 0){
            int x;

            scanf("%d", &x);
            Push(&q, x);
        }
        else if(strcmp(array, "pop") == 0){
            printf("%d\n",Pop(&q));
        }
        else if(strcmp(array, "size") == 0){
            printf("%d\n",Size(&q));
        }
        else if(strcmp(array, "empty") == 0){
            printf("%d\n",Empty(&q));
        }
        else if(strcmp(array, "front") == 0){
            printf("%d\n",Front(&q));
        }
        else if(strcmp(array, "back") == 0){
            printf("%d\n",Back(&q));
        }
    }

    return 0;
}

void Queueinit(Queue *pq){
    pq->front = 0;
    pq->rear = 0;
    pq->size = 0;
}
void Push(Queue *pq, int data){
    pq->rear = Nextindex(pq->rear);
    pq->arr[pq->rear] = data;
    pq->size = pq->size + 1;
}
int Empty(Queue *pq){
    if(pq->front == pq->rear){
        return True;
    }
    else{
        return False;
    }
}
int Nextindex(int pos){
    if(pos == MAX_LEN - 1 ){
        return 0;
    }
    else{
        return pos = pos + 1;
    }
}
int Front(Queue *pq){
    if(Empty(pq)){
        return -1;
    }
    else{
        return pq->arr[pq->front+1]; 
    }

}
int Back(Queue *pq){
    if(Empty(pq)){
        return -1;
    }
    else{
        return pq->arr[pq->rear];
    }
}
int Size(Queue *pq){
    if(Empty(pq)){
        return 0;
    }
    else{
    return pq->size;
    }
}
int Pop(Queue *pq){ 
    if(Empty(pq)){
        return -1;
    }
    else{
        pq->size = pq->size - 1;
        pq->front = Nextindex(pq->front); 
        int rdata = pq->arr[pq->front];
        return rdata;
    }
}