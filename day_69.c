#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct {
    int vertex;
    int weight;
} Edge;
typedef struct {
    Edge* edges;
    int size;
    int capacity;
} MinHeap;
void swap(Edge* a, Edge* b) {
    Edge temp = *a;
    *a = *b;
    *b = temp;
}
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->edges = (Edge*)malloc(capacity * sizeof(Edge));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    return minHeap;
}
void insert(MinHeap* minHeap, int vertex, int weight) {
    if (minHeap->size == minHeap->capacity) {
        return;
    }
    minHeap->edges[minHeap->size].vertex = vertex;
    minHeap->edges[minHeap->size].weight = weight;
    minHeap->size++;
    int i = minHeap->size - 1;
    while (i > 0 && minHeap->edges[i].weight < minHeap->edges[(i - 1) / 2].weight) {
        swap(&minHeap->edges[i], &minHeap->edges[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
Edge extractMin(MinHeap* minHeap) {
    Edge minEdge = minHeap->edges[0];
    minHeap->edges[0] = minHeap->edges[minHeap->size - 1];
    minHeap->size--;
    int i = 0;
    while (2 * i + 1 < minHeap->size) {
        int smallest = i;
        if (2 * i + 1 < minHeap->size && minHeap->edges[2 * i + 1].weight < minHeap->edges[smallest].weight) {
            smallest = 2 * i + 1;
        }
        if (2 * i + 2 < minHeap->size && minHeap->edges[2 * i + 2].weight < minHeap->edges[smallest].weight) {
            smallest = 2 * i + 2;
        }
        if (smallest == i) {
            break;
        }
        swap(&minHeap->edges[i], &minHeap->edges[smallest]);
        i = smallest;
    }
    return minEdge;
}
int main() {
    int V, E, source;
    scanf("%d %d %d", &V, &E, &source);

    int** adj = (int**)malloc(V * sizeof(int*));
    int* adjSize = (int*)calloc(V, sizeof(int));
    int* dist = (int*)malloc(V * sizeof(int));

    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(V * sizeof(int));
        dist[i] = INT_MAX;
    }

    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u; 
    }
    MinHeap* minHeap = createMinHeap(V);
    insert(minHeap, source, 0);
    dist[source] = 0;
    while (minHeap->size > 0) {
        Edge minEdge = extractMin(minHeap);
        int u = minEdge.vertex;
        for (int i = 0; i < adjSize[u]; i++) {
            int v = adj[u][i];
            int weight = 1; 
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                insert(minHeap, v, dist[v]);
            }
        }
    }
    for (int i = 0; i < V; i++) {
        printf("Distance from source %d to vertex %d is %d\n", source, i, dist[i]);
    }
    return 0;
}