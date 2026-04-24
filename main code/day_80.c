#include <stdio.h>

#define INF 1000000000

int main() {
    int n, m, distanceThreshold;
    scanf("%d %d", &n, &m);

    int dist[101][101];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        dist[u][v] = w;
        dist[v][u] = w;
    }

    scanf("%d", &distanceThreshold);

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int result = -1, minCount = INF;

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] <= distanceThreshold)
                count++;
        }
        if (count <= minCount) {
            minCount = count;
            result = i;
        }
    }

    printf("%d", result);

    return 0;
}