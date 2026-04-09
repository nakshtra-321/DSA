#include <stdio.h>
#include <stdlib.h>

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* adjSize = (int*)calloc(numCourses, sizeof(int));
    int* indegree = (int*)calloc(numCourses, sizeof(int));
    
    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(numCourses * sizeof(int));
    }
    
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        adj[b][adjSize[b]++] = a;
        indegree[a]++;
    }
    
    int* queue = (int*)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;
    
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    
    int* order = (int*)malloc(numCourses * sizeof(int));
    int count = 0;
    
    while (front < rear) {
        int node = queue[front++];
        order[count++] = node;
        
        for (int i = 0; i < adjSize[node]; i++) {
            int nbr = adj[node][i];
            indegree[nbr]--;
            if (indegree[nbr] == 0) {
                queue[rear++] = nbr;
            }
        }
    }
    
    if (count == numCourses) {
        *returnSize = numCourses;
        return order;
    }
    
    *returnSize = 0;
    return NULL;
}