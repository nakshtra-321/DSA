#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int cameras = 0;

int dfs(struct TreeNode* root) {
    if (!root) return 1;

    int left = dfs(root->left);
    int right = dfs(root->right);

    if (left == -1 || right == -1) {
        cameras++;
        return 0;
    }

    if (left == 0 || right == 0) return 1;

    return -1;
}

int minCameraCover(struct TreeNode* root) {
    if (dfs(root) == -1) cameras++;
    return cameras;
}