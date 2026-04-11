#include <stdio.h>
#include <stdlib.h>
#define INF 1000000
typedef struct {
    int u, v, w;
} Edge;
int main() {
    int V, E, source;
    scanf("%d %d %d", &V, &E, &source);
    Edge* edges = (Edge*)malloc(E * sizeof(Edge));
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    int* dist = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
    }
    dist[source] = 0;
    for (int i = 1; i < V; i++) {
        for (int j = 0; j < E; j++) {
            if (dist[edges[j].u] != INF && dist[edges[j].u] + edges[j].w < dist[edges[j].v]) {
                dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
            }
        }
    }
    for (int j = 0; j < E; j++) {
        if (dist[edges[j].u] != INF && dist[edges[j].u] + edges[j].w < dist[edges[j].v]) {
            printf("NEGATIVE CYCLE\n");
            free(edges);
            free(dist);
            return 0;
        }
    }
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF) {
            printf("INF ");
        } else {
            printf("%d ", dist[i]);
        }
    }
    printf("\n");
    free(edges);
    free(dist);
    return 0;
}