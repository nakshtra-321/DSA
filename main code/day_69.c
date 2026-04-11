#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 101

int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, min_index = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

int networkDelayTime(int times[][3], int timesSize, int n, int k) {
    int graph[MAX][MAX];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];
        graph[u][v] = w;
    }

    int dist[MAX];
    int visited[MAX] = {0};

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    dist[k] = 0;

    for (int count = 1; count <= n - 1; count++) {
        int u = minDistance(dist, visited, n);
        if (u == -1) break;
        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] != INT_MAX &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    int max = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) return -1;
        if (dist[i] > max) max = dist[i];
    }

    return max;
}

int main() {
    int times[][3] = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4, k = 2;
    int timesSize = sizeof(times)/sizeof(times[0]);

    int result = networkDelayTime(times, timesSize, n, k);
    printf("%d\n", result);

    return 0;
}