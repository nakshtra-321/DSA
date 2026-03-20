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

void inorder(struct TreeNode* root) {
    struct Stack s;
    s.top = -1;
    struct TreeNode* curr = root;

    while (curr != NULL || !isEmpty(&s)) {
        while (curr != NULL) {
            push(&s, curr);
            curr = curr->left;
        }
        curr = pop(&s);
        printf("%d ", curr->val);
        curr = curr->right;
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

    inorder(root);

    return 0;
}