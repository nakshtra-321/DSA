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

// Build tree from level-order input
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

// LCA in Binary Tree
struct Node* LCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->data == n1 || root->data == n2) return root;
    struct Node* left = LCA(root->left, n1, n2);
    struct Node* right = LCA(root->right, n1, n2);
    if (left && right) return root;
    return left ? left : right;
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    struct Node* root = buildTree(arr, N);
    struct Node* lca = LCA(root, n1, n2);
    if (lca) printf("%d\n", lca->data);
    return 0;
}