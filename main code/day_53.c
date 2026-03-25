#include <stdio.h>
#include <stdlib.h>

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

// Queue structure for BFS
struct Queue {
    struct Node** arr;
    int front, rear, size;
};

struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct Node**)malloc(size * sizeof(struct Node*));
    q->front = q->rear = 0;
    q->size = size;
    return q;
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[q->rear++] = node;
}

struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Level Order Traversal
void levelOrder(struct Node* root) {
    if (!root) {
        printf("[]\n");
        return;
    }
    struct Queue* q = createQueue(2000);
    enqueue(q, root);

    while (!isEmpty(q)) {
        int count = q->rear - q->front; // number of nodes at current level
        printf("[");
        for (int i = 0; i < count; i++) {
            struct Node* node = dequeue(q);
            printf("%d", node->data);
            if (i < count - 1) printf(",");
            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }
        printf("]\n");
    }
}

int main() {
    // Example tree: [3,9,20,null,null,15,7]
    struct Node* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    levelOrder(root);
    return 0;
}