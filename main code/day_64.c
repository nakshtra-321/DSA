#include <stdio.h>
#include <stdlib.h>

struct Pair {
    int x, y;
};

int orangesRotting(int** grid, int m, int* n) {
    int rows = m, cols = *n;
    struct Pair queue[100];
    int front = 0, rear = 0;

    int fresh = 0, minutes = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                queue[rear++] = (struct Pair){i, j};
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    while (front < rear && fresh > 0) {
        int size = rear - front;
        minutes++;

        for (int i = 0; i < size; i++) {
            struct Pair p = queue[front++];
            for (int d = 0; d < 4; d++) {
                int nx = p.x + dirs[d][0];
                int ny = p.y + dirs[d][1];

                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    fresh--;
                    queue[rear++] = (struct Pair){nx, ny};
                }
            }
        }
    }

    if (fresh > 0) return -1;
    return minutes;
}