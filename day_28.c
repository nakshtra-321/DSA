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
    int n;
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
    if (tail) tail->next = head;
    Node* cur = head;
    if (cur) {
        do {
            printf("%d", cur->data);
            cur = cur->next;
            if (cur != head) printf(" ");
        } while (cur != head);
    }
    printf("\n");
    return 0;
}