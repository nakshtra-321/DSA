#include <stdio.h>
#include <string.h>
#define MAX_EDGES 1000
void findRedundantConnection(int edges[MAX_EDGES][2], int n, int result[2]) {
    int parent[MAX_EDGES];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < n; i++) {
        int u = edges[i][0] - 1;
        int v = edges[i][1] - 1;

        // Find the root of u and v
        int rootU = u;
        while (parent[rootU] != rootU) {
            rootU = parent[rootU];
        }
        int rootV = v;
        while (parent[rootV] != rootV) {
            rootV = parent[rootV];
        }

        // If u and v have the same root, we found the redundant edge
        if (rootU == rootV) {
            result[0] = edges[i][0];
            result[1] = edges[i][1];
            return;
        }

        // Union the sets
        parent[rootV] = rootU;
    }
}
int main() {
    int edges[MAX_EDGES][2];
    int n;

    printf("Enter the number of edges: ");
    scanf("%d", &n);

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    int result[2];
    findRedundantConnection(edges, n, result);
    printf("Redundant edge: [%d, %d]\n", result[0], result[1]);

    return 0;
}