#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); // number of rows and columns

    int matrix[n][n];
    int isIdentity = 1; // assume it's identity until proven otherwise

    // Input matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check conditions
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j && matrix[i][j] != 1) { // diagonal must be 1
                isIdentity = 0;
                break;
            } else if (i != j && matrix[i][j] != 0) { // non-diagonal must be 0
                isIdentity = 0;
                break;
            }
        }
        if (!isIdentity)
            break;
    }

    // Output result
    if (isIdentity)
        printf("Identity Matrix\n");
    else
        printf("Not an Identity Matrix\n");

    return 0;
}