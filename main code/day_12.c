#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    // Input the matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int isToeplitz = 1; // assume true

    // Check diagonals
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] != matrix[i - 1][j - 1]) {
                isToeplitz = 0;
                break;
            }
        }
        if (!isToeplitz)
            break;
    }

    if (isToeplitz)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}