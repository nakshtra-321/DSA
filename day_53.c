#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level-order array
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node** nodes = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) nodes[i] = NULL;
        else nodes[i] = newNode(arr[i]);
    }
    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int leftIndex = 2*i + 1;
            int rightIndex = 2*i + 2;
            if (leftIndex < n) nodes[i]->left = nodes[leftIndex];
            if (rightIndex < n) nodes[i]->right = nodes[rightIndex];
        }
    }
    return nodes[0];
}

// Structure for queue
struct QNode {
    struct Node* node;
    int hd; // horizontal distance
};

struct Queue {
    struct QNode* arr;
    int front, rear, size;
};

struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct QNode*)malloc(size * sizeof(struct QNode));
    q->front = q->rear = 0;
    q->size = size;
    return q;
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

void enqueue(struct Queue* q, struct Node* node, int hd) {
    q->arr[q->rear].node = node;
    q->arr[q->rear].hd = hd;
    q->rear++;
}

struct QNode dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Map structure
struct List {
    int* values;
    int count;
};

void verticalOrder(struct Node* root, int n) {
    if (!root) return;
    struct Queue* q = createQueue(n*2);
    enqueue(q, root, 0);

    int minHd = INT_MAX, maxHd = INT_MIN;
    struct List* map = (struct List*)malloc(n*2 * sizeof(struct List));
    for (int i = 0; i < n*2; i++) {
        map[i].values = (int*)malloc(n * sizeof(int));
        map[i].count = 0;
    }

    while (!isEmpty(q)) {
        struct QNode temp = dequeue(q);
        struct Node* node = temp.node;
        int hd = temp.hd;
        if (node) {
            if (hd < minHd) minHd = hd;
            if (hd > maxHd) maxHd = hd;
            int idx = hd + n; 
            map[idx].values[map[idx].count++] = node->data;
            if (node->left) enqueue(q, node->left, hd-1);
            if (node->right) enqueue(q, node->right, hd+1);
        }
    }

    for (int hd = minHd; hd <= maxHd; hd++) {
        int idx = hd + n;
        for (int i = 0; i < map[idx].count; i++) {
            printf("%d ", map[idx].values[i]);
        }
        printf("\n");
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, N);
    verticalOrder(root, N);
    return 0;
}