#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_POINTS 1000
int manhattanDistance(int* point1, int* point2) {
    return abs(point1[0] - point2[0]) + abs(point1[1] - point2[1]);
}
int minCostConnectPoints(int points[MAX_POINTS][2], int n) {
    int minCost = 0;
    int visited[MAX_POINTS] = {0};
    visited[0] = 1; // Start from the first point

    for (int i = 1; i < n; i++) {
        int minDist = __INT_MAX__;
        int nextPoint = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int dist = manhattanDistance(points[i], points[j]);
                if (dist < minDist) {
                    minDist = dist;
                    nextPoint = j;
                }
            }
        }

        visited[nextPoint] = 1;
        minCost += minDist;
    }

    return minCost;
}
int main() {
    int points[MAX_POINTS][2];
    int n;

    printf("Enter the number of points: ");
    scanf("%d", &n);

    printf("Enter the coordinates of the points (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i][0], &points[i][1]);
    }

    int result = minCostConnectPoints(points, n);
    printf("Minimum cost to connect all points: %d\n", result);

    return 0;
}