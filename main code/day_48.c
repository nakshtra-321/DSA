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

int isLeaf(struct Node* node) {
    return node != NULL && node->left == NULL && node->right == NULL;
}

int sumOfLeftLeaves(struct Node* root) {
    if (root == NULL) return 0;
    int sum = 0;
    if (isLeaf(root->left)) sum += root->left->data;
    else sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);
    return sum;
}

int main() {
    struct Node* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    printf("Sum of left leaves: %d\n", sumOfLeftLeaves(root));
    return 0;
}