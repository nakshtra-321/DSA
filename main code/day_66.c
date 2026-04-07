#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

int dfs(int v, struct Node* adj[], int visited[], int recStack[]) {
    visited[v] = 1;
    recStack[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        int u = temp->vertex;
        if (!visited[u]) {
            if (dfs(u, adj, visited, recStack)) return 1;
        } else if (recStack[u]) {
            return 1;
        }
        temp = temp->next;
    }

    recStack[v] = 0;
    return 0;
}

int canFinish(int numCourses, int prerequisites[][2], int size) {
    struct Node* adj[numCourses];
    int visited[numCourses], recStack[numCourses];

    for (int i = 0; i < numCourses; i++) {
        adj[i] = NULL;
        visited[i] = 0;
        recStack[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        addEdge(adj, b, a);
    }

    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack)) return 0;
        }
    }

    return 1;
}