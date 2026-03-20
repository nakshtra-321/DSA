#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

struct Stack {
    struct TreeNode* data[100];
    int top;
};

void push(struct Stack* s, struct TreeNode* node) {
    s->data[++(s->top)] = node;
}

struct TreeNode* pop(struct Stack* s) {
    return s->data[(s->top)--];
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void preorder(struct TreeNode* root) {
    if (root == NULL) return;

    struct Stack s;
    s.top = -1;

    push(&s, root);

    while (!isEmpty(&s)) {
        struct TreeNode* curr = pop(&s);
        printf("%d ", curr->val);

        if (curr->right) push(&s, curr->right);
        if (curr->left) push(&s, curr->left);
    }
}

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int main() {
    struct TreeNode* root = newNode(1);
    root->right = newNode(2);
    root->right->left = newNode(3);

    preorder(root);

    return 0;
}