#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int isSymmetric(struct TreeNode* root) {
    if (!root) return 1;

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    queue[rear++] = root;

    while (front < rear) {
        struct TreeNode* a = queue[front++];
        struct TreeNode* b = queue[front++];

        if (!a && !b) continue;
        if (!a || !b) return 0;
        if (a->val != b->val) return 0;

        queue[rear++] = a->left;
        queue[rear++] = b->right;
        queue[rear++] = a->right;
        queue[rear++] = b->left;
    }

    return 1;
}