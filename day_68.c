#include <stdio.h>
#include <stdlib.h>

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int** adj = (int**)malloc(V * sizeof(int*));
    int* adjSize = (int*)calloc(V, sizeof(int));
    int* indegree = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(V * sizeof(int));
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v;
        indegree[v]++;
    }

    int* queue = (int*)malloc(V * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        for (int i = 0; i < adjSize[node]; i++) {
            int v = adj[node][i];
            indegree[v]--;
            if (indegree[v] == 0) {
                queue[rear++] = v;
            }
        }
    }

    if (count != V) {
        printf("Cycle detected");
    }

    return 0;
}