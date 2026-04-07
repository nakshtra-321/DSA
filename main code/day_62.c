#include <stdio.h>
#include <stdlib.h>

int visited[1001];

void dfs(int room, int** rooms, int* roomsColSize) {
    visited[room] = 1;

    for (int i = 0; i < roomsColSize[room]; i++) {
        int key = rooms[room][i];
        if (!visited[key]) {
            dfs(key, rooms, roomsColSize);
        }
    }
}

int canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    for (int i = 0; i < roomsSize; i++) visited[i] = 0;

    dfs(0, rooms, roomsColSize);

    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) return 0;
    }

    return 1;
}