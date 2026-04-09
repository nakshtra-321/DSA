#include <stdio.h>
#include <stdlib.h>

void dfs(int node, int** adj, int* adjSize, int* visited, int* stack, int* top) {
    visited[node] = 1;
    for (int i = 0; i < adjSize[node]; i++) {
        int v = adj[node][i];
        if (!visited[v]) dfs(v, adj, adjSize, visited, stack, top);
    }
    stack[(*top)++] = node;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int** adj = (int**)malloc(V * sizeof(int*));
    int* adjSize = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(V * sizeof(int));
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v;
    }

    int* visited = (int*)calloc(V, sizeof(int));
    int* stack = (int*)malloc(V * sizeof(int));
    int top = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) dfs(i, adj, adjSize, visited, stack, &top);
    }

    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}