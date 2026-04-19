#include <stdio.h>
#include <stdlib.h>

int timer;
int disc[100005], low[100005], visited[100005];

int adj[100005][1005];
int size[100005];

int res[100005][2];
int resSize;

void dfs(int u, int parent) {
    visited[u] = 1;
    disc[u] = low[u] = timer++;

    for(int i = 0; i < size[u]; i++) {
        int v = adj[u][i];

        if(v == parent) continue;

        if(!visited[v]) {
            dfs(v, u);
            if(low[v] > disc[u]) {
                res[resSize][0] = u;
                res[resSize][1] = v;
                resSize++;
            }
            if(low[v] < low[u]) low[u] = low[v];
        } else {
            if(disc[v] < low[u]) low[u] = disc[v];
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        size[i] = 0;
        visited[i] = 0;
    }

    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    timer = 0;
    resSize = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, -1);
        }
    }

    for(int i = 0; i < resSize; i++) {
        printf("%d %d\n", res[i][0], res[i][1]);
    }

    return 0;
}