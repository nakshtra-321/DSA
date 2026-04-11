#include <stdio.h>
#include <limits.h>

int findCheapestPrice(int n, int flights[][3], int flightsSize, int src, int dst, int k) {
    int dist[101];
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 0; i <= k; i++) {
        int temp[101];
        for (int j = 0; j < n; j++) temp[j] = dist[j];

        for (int j = 0; j < flightsSize; j++) {
            int u = flights[j][0];
            int v = flights[j][1];
            int w = flights[j][2];

            if (dist[u] != INT_MAX && dist[u] + w < temp[v]) {
                temp[v] = dist[u] + w;
            }
        }

        for (int j = 0; j < n; j++) dist[j] = temp[j];
    }

    return dist[dst] == INT_MAX ? -1 : dist[dst];
}

int main() {
    int flights[][3] = {{0,1,100},{1,2,100},{0,2,500}};
    int n = 3, src = 0, dst = 2, k = 1;
    int flightsSize = sizeof(flights)/sizeof(flights[0]);

    int result = findCheapestPrice(n, flights, flightsSize, src, dst, k);
    printf("%d\n", result);

    return 0;
}