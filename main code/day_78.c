#include <stdio.h>
#include <stdlib.h>

int timer;
int disc[100005], low[100005], visited[100005], ap[100005];

int adj[100005][1005];
int size[100005];

void dfs(int u, int parent) {
    visited[u] = 1;
    disc[u] = low[u] = timer++;
    int children = 0;

    for(int i = 0; i < size[u]; i++) {
        int v = adj[u][i];

        if(v == parent) continue;

        if(!visited[v]) {
            children++;
            dfs(v, u);

            if(low[v] < low[u]) low[u] = low[v];

            if(parent != -1 && low[v] >= disc[u]) {
                ap[u] = 1;
            }
        } else {
            if(disc[v] < low[u]) low[u] = disc[v];
        }
    }

    if(parent == -1 && children > 1) {
        ap[u] = 1;
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    for(int i = 0; i < V; i++) {
        size[i] = 0;
        visited[i] = 0;
        ap[i] = 0;
    }

    for(int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    timer = 0;

    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            dfs(i, -1);
        }
    }

    int found = 0;
    for(int i = 0; i < V; i++) {
        if(ap[i]) {
            printf("%d ", i);
            found = 1;
        }
    }

    if(!found) printf("-1");

    return 0;
}