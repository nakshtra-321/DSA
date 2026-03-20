#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* nodes[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) nodes[i] = NULL;
        else nodes[i] = newNode(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int l = 2*i + 1;
            int r = 2*i + 2;
            if (l < n) nodes[i]->left = nodes[l];
            if (r < n) nodes[i]->right = nodes[r];
        }
    }

    return nodes[0];
}

int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return (left > right ? left : right) + 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);

    printf("%d", maxDepth(root));

    return 0;
}