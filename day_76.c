#include <stdio.h>
#include <stdlib.h>

int visited[100005];
int adj[100005][1005];
int size[100005];

void dfs(int node) {
    visited[node] = 1;
    for(int i = 0; i < size[node]; i++) {
        int next = adj[node][i];
        if(!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++) {
        size[i] = 0;
        visited[i] = 0;
    }

    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    int count = 0;

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i);
            count++;
        }
    }

    printf("%d", count);
    return 0;
}