#include <stdio.h>
#include <limits.h>

#define MAX 10
#define INF INT_MAX

int n; // vertices
int graph[MAX][MAX];

int minDist(int dist[], int visited[]) {
    int min = INF, idx = -1;
    for (int i = 0; i < n; i++)
        if (!visited[i] && dist[i] < min) { min = dist[i]; idx = i; }
    return idx;
}

void dijkstra(int src) {
    int dist[MAX], visited[MAX], parent[MAX];
    for (int i = 0; i < n; i++) { dist[i] = INF; visited[i] = 0; parent[i] = -1; }
    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDist(dist, visited);
        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("Shortest distances from node %d:\n", src);
    for (int i = 0; i < n; i++) {
        if (i == src) continue;
        printf("  To %d: ", i);
        if (dist[i] == INF) printf("unreachable");
        else printf("%d", dist[i]);
        printf("\n");
    }
}

int main() {
    n = 5;
    // weighted adjacency matrix
    int g[5][5] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = g[i][j];

    printf("Graph (weighted adjacency matrix):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%4d", graph[i][j]);
        printf("\n");
    }
    printf("\n");

    dijkstra(0);
    return 0;
}
