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

int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

Node* getIntersection(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    Node *cur1 = head1, *cur2 = head2;
    int diff = abs(len1 - len2);
    if (len1 > len2) while (diff--) cur1 = cur1->next;
    else while (diff--) cur2 = cur2->next;
    while (cur1 && cur2) {
        if (cur1->data == cur2->data) return cur1;
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return NULL;
}

int main() {
    int n, m, x;
    scanf("%d", &n);
    Node *head1 = NULL, *tail1 = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        Node* node = newNode(x);
        if (!head1) head1 = tail1 = node;
        else { tail1->next = node; tail1 = node; }
    }

    scanf("%d", &m);
    Node *head2 = NULL, *tail2 = NULL;
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        Node* node = newNode(x);
        if (!head2) head2 = tail2 = node;
        else { tail2->next = node; tail2 = node; }
    }

    Node* inter = getIntersection(head1, head2);
    if (inter) printf("%d\n", inter->data);
    else printf("No Intersection\n");
    return 0;
}