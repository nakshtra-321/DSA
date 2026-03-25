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

// Recursive LCA function for Binary Tree
struct Node* lowestCommonAncestor(struct Node* root, int p, int q) {
    if (root == NULL) return NULL;
    if (root->data == p || root->data == q) return root;

    struct Node* left = lowestCommonAncestor(root->left, p, q);
    struct Node* right = lowestCommonAncestor(root->right, p, q);

    if (left && right) return root;
    return left ? left : right;
}

// Build tree from array (level-order, -1 = NULL)
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node** nodes = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) nodes[i] = NULL;
        else nodes[i] = newNode(arr[i]);
    }
    for (int i = 0; i < n; i++) {
        if (nodes[i]) {
            int l = 2*i + 1, r = 2*i + 2;
            if (l < n) nodes[i]->left = nodes[l];
            if (r < n) nodes[i]->right = nodes[r];
        }
    }
    return nodes[0];
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    int p, q;
    scanf("%d %d", &p, &q);

    struct Node* root = buildTree(arr, N);
    struct Node* lca = lowestCommonAncestor(root, p, q);
    if (lca) printf("%d\n", lca->data);
    return 0;
}