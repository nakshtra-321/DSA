#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    struct TreeNode* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int* result = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;

            if (i == size - 1) {
                result[*returnSize] = node->val;
                (*returnSize)++;
            }
        }
    }

    return result;
}