#include <stdio.h>
#define MAX_CITIES 200
void dfs(int isConnected[MAX_CITIES][MAX_CITIES], int visited[MAX_CITIES], int city, int n) {
    visited[city] = 1;
    for (int i = 0; i < n; i++) {
        if (isConnected[city][i] == 1 && !visited[i]) {
            dfs(isConnected, visited, i, n);
        }
    }
}
int findCircleNum(int isConnected[MAX_CITIES][MAX_CITIES], int n) {
    int visited[MAX_CITIES] = {0};
    int provinceCount = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(isConnected, visited, i, n);
            provinceCount++;
        }
    }

    return provinceCount;
}
int main() {
    int n;
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    int isConnected[MAX_CITIES][MAX_CITIES];
    printf("Enter the connectivity matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &isConnected[i][j]);
        }
    }

    int result = findCircleNum(isConnected, n);
    printf("Number of provinces: %d\n", result);

    return 0;
}