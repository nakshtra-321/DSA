#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100005
int visited[MAX_NODES];
int adj[MAX_NODES][1005];
int weight[MAX_NODES][1005];
int size[MAX_NODES];
void prim(int n) {
    int totalWeight = 0;
    visited[1] = 1; // Start from the first node

    for(int count = 1; count < n; count++) {
        int minEdge = 1000000000; // A large number
        int nextNode = -1;

        for(int i = 1; i <= n; i++) {
            if(visited[i]) {
                for(int j = 0; j < size[i]; j++) {
                    int v = adj[i][j];
                    if(!visited[v] && weight[i][j] < minEdge) {
                        minEdge = weight[i][j];
                        nextNode = v;
                    }
                }
            }
        }

        if(nextNode != -1) {
            visited[nextNode] = 1;
            totalWeight += minEdge;
        }
    }

    printf("%d", totalWeight);
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++) {
        size[i] = 0;
        visited[i] = 0;
    }

    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][size[u]] = v;
        weight[u][size[u]] = w;
        size[u]++;
        adj[v][size[v]] = u;
        weight[v][size[v]] = w;
        size[v]++;
    }

    prim(n);
    return 0;
}