#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} Node;

Node* newNode(int c, int e) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->coeff = c;
    temp->exp = e;
    temp->next = NULL;
    return temp;
}

int main() {
    int n;
    scanf("%d", &n);
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int c, e;
        scanf("%d %d", &c, &e);
        Node* node = newNode(c, e);
        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
    Node* cur = head;
    while (cur) {
        printf("%d", cur->coeff);
        if (cur->exp > 0) printf("x^%d", cur->exp);
        if (cur->next) printf(" + ");
        cur = cur->next;
    }
    printf("\n");
    return 0;
}