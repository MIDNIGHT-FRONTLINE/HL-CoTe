#include <stdio.h>
#define MAX 1001

int graph[MAX][MAX] = {0};
int visited_dfs[MAX] = {0};
int visited_bfs[MAX] = {0};
int queue[MAX];

void dfs(int v, int vertices);
void bfs(int v, int vertices);

int main() {
    int vertices, edges, start_vertex;
    scanf("%d %d %d", &vertices, &edges, &start_vertex);

    while (edges--) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    dfs(start_vertex, vertices);
    printf("\n");
    bfs(start_vertex, vertices);

    return 0;
}

void dfs(int v, int vertices) {
    visited_dfs[v] = 1;
    printf("%d ", v);

    for (int w = 1; w <= vertices; w++) {
        if (graph[v][w] && !visited_dfs[w]) {
            dfs(w, vertices);
        }
    }
}

void bfs(int start, int vertices) {
    int front = 0, rear = 0;
    queue[rear++] = start;
    visited_bfs[start] = 1;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int w = 1; w <= vertices; w++) {
            if (graph[v][w] && !visited_bfs[w]) {
                queue[rear++] = w;
                visited_bfs[w] = 1;
            }
        }
    }
}