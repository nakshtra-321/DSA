#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int v;
    struct Node* next;
} Node;

Node** adj;
Node** rev;
int* visited;
int* stack;
int top = -1;

void addEdge(Node** graph, int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->next = graph[u];
    graph[u] = newNode;
}

void dfs1(int v) {
    visited[v] = 1;
    Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->v])
            dfs1(temp->v);
        temp = temp->next;
    }
    stack[++top] = v;
}

void dfs2(int v) {
    visited[v] = 1;
    Node* temp = rev[v];
    while (temp) {
        if (!visited[temp->v])
            dfs2(temp->v);
        temp = temp->next;
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    adj = (Node**)malloc(V * sizeof(Node*));
    rev = (Node**)malloc(V * sizeof(Node*));
    visited = (int*)calloc(V, sizeof(int));
    stack = (int*)malloc(V * sizeof(int));

    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        rev[i] = NULL;
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        addEdge(rev, v, u);
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs1(i);
    }

    for (int i = 0; i < V; i++)
        visited[i] = 0;

    int count = 0;

    while (top >= 0) {
        int v = stack[top--];
        if (!visited[v]) {
            dfs2(v);
            count++;
        }
    }

    printf("%d", count);

    return 0;
}