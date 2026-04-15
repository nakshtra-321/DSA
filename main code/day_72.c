#include <stdio.h>
#include <limits.h>
#define MAX_CITIES 15
int tsp(int cost[MAX_CITIES][MAX_CITIES], int n, int pos, int visited) {
    if (visited == (1 << n) - 1) {
        return cost[pos][0]; // Return to starting city
    }
    int minCost = INT_MAX;
    for (int city = 0; city < n; city++) {
        if ((visited & (1 << city)) == 0) { // If city is not visited
            int newCost = cost[pos][city] + tsp(cost, n, city, visited | (1 << city));
            if (newCost < minCost) {
                minCost = newCost;
            }
        }
    }
    return minCost;
}
int main() {
    int cost[MAX_CITIES][MAX_CITIES];
    int n;

    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    int result = tsp(cost, n, 0, 1);
    printf("Minimum cost of the tour: %d\n", result);

    return 0;
}