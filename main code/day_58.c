#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int findIndex(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

struct TreeNode* build(int preorder[], int inorder[], int start, int end, int *preIndex) {
    if (start > end)
        return NULL;

    struct TreeNode* root = createNode(preorder[*preIndex]);
    (*preIndex)++;

    if (start == end)
        return root;

    int index = findIndex(inorder, start, end, root->val);

    root->left = build(preorder, inorder, start, index - 1, preIndex);
    root->right = build(preorder, inorder, index + 1, end, preIndex);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int preIndex = 0;
    return build(preorder, inorder, 0, preorderSize - 1, &preIndex);
}