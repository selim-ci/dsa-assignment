#include <stdio.h>
#include <string.h>

#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int n; // number of vertices

void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

// BFS using queue
void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    memset(visited, 0, sizeof(visited));

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS: ");
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (adj[v][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

void dfsHelper(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i])
            dfsHelper(i);
    }
}

void DFS(int start) {
    memset(visited, 0, sizeof(visited));
    printf("DFS: ");
    dfsHelper(start);
    printf("\n");
}

int main() {
    n = 6;
    memset(adj, 0, sizeof(adj));

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);

    printf("Graph adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
    printf("\n");

    BFS(0);
    DFS(0);

    return 0;
}
