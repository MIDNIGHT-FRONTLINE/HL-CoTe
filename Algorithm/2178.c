#include <stdio.h>

#define MAX 10001
#define GRAPH_MAX 101

int graph[GRAPH_MAX][GRAPH_MAX] = {0, };
int q[MAX][2];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, m;

int bfs();

int main() {
    scanf("%d %d", &n, &m);
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) 
            scanf("%1d", &graph[i][j]);
   
    printf("%d", bfs());
    return 0;
}

int bfs() {
    int front = 0, rear = 0;
    q[rear][0] = 1;
    q[rear][1] = 1;
    rear++;
    
    while(front < rear) {
        int x = q[front][0], y = q[front][1];
        front++;
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            
            if(nx < 1 || ny < 1 || nx > n || ny > m || graph[nx][ny] != 1)
                continue;

            graph[nx][ny] = graph[x][y] + 1;
            q[rear][0] = nx;
            q[rear][1] = ny;
            rear++;
        }
    }
    return graph[n][m];
}