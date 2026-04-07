#include <stdio.h>

int visited[201];

void dfs(int city, int n, int isConnected[n][n]) {
    visited[city] = 1;
    for (int i = 0; i < n; i++) {
        if (isConnected[city][i] == 1 && !visited[i]) {
            dfs(i, n, isConnected);
        }
    }
}

int findCircleNum(int n, int isConnected[n][n]) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n, isConnected);
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int isConnected[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &isConnected[i][j]);

    int result = findCircleNum(n, isConnected);
    printf("%d\n", result);

    return 0;
}