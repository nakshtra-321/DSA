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

struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

struct Node* lowestCommonAncestor(struct Node* root, int p, int q) {
    if (root == NULL) return NULL;
    if (root->data > p && root->data > q) return lowestCommonAncestor(root->left, p, q);
    if (root->data < p && root->data < q) return lowestCommonAncestor(root->right, p, q);
    return root;
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 6);
    insert(root, 2);
    insert(root, 8);
    insert(root, 0);
    insert(root, 4);
    insert(root, 7);
    insert(root, 9);
    insert(root, 3);
    insert(root, 5);

    int p = 2, q = 8;
    struct Node* lca = lowestCommonAncestor(root, p, q);
    if (lca) printf("LCA of %d and %d is %d\n", p, q, lca->data);

    p = 2; q = 4;
    lca = lowestCommonAncestor(root, p, q);
    if (lca) printf("LCA of %d and %d is %d\n", p, q, lca->data);

    p = 2; q = 1;
    lca = lowestCommonAncestor(root, p, q);
    if (lca) printf("LCA of %d and %d is %d\n", p, q, lca->data);

    return 0;
}