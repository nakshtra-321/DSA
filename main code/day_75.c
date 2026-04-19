#include <stdio.h>

int graph[105][105];
int size[105];
int color[105];

int isBipartite(int n) {
    for(int i = 0; i < n; i++) {
        if(color[i] == -1) {
            int queue[105], front = 0, rear = 0;
            queue[rear++] = i;
            color[i] = 0;

            while(front < rear) {
                int node = queue[front++];

                for(int j = 0; j < size[node]; j++) {
                    int next = graph[node][j];

                    if(color[next] == -1) {
                        color[next] = 1 - color[node];
                        queue[rear++] = next;
                    } else if(color[next] == color[node]) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        size[i] = 0;
        color[i] = -1;
    }

    for(int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &graph[i][size[i]++]);
        }
    }

    if(isBipartite(n)) printf("true");
    else printf("false");

    return 0;
}