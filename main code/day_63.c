#include <stdio.h>

void dfs(int** image, int m, int n, int r, int c, int oldColor, int newColor) {
    if (r < 0 || r >= m || c < 0 || c >= n) return;
    if (image[r][c] != oldColor) return;

    image[r][c] = newColor;

    dfs(image, m, n, r + 1, c, oldColor, newColor);
    dfs(image, m, n, r - 1, c, oldColor, newColor);
    dfs(image, m, n, r, c + 1, oldColor, newColor);
    dfs(image, m, n, r, c - 1, oldColor, newColor);
}

int** floodFill(int** image, int m, int* n, int sr, int sc, int color) {
    int oldColor = image[sr][sc];
    if (oldColor == color) return image;

    dfs(image, m, *n, sr, sc, oldColor, color);
    return image;
}