#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main() {
    int n, k;
    scanf("%d", &n);
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        Node* node = newNode(x);
        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
    scanf("%d", &k);
    if (n == 0 || k == 0) {
        Node* cur = head;
        while (cur) {
            printf("%d", cur->data);
            if (cur->next) printf(" ");
            cur = cur->next;
        }
        printf("\n");
        return 0;
    }
    tail->next = head;
    k = k % n;
    int steps = n - k;
    Node* newTail = head;
    for (int i = 1; i < steps; i++) newTail = newTail->next;
    head = newTail->next;
    newTail->next = NULL;
    Node* cur = head;
    while (cur) {
        printf("%d", cur->data);
        if (cur->next) printf(" ");
        cur = cur->next;
    }
    printf("\n");
    return 0;
}