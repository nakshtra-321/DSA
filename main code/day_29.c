#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* newNode(int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->val = val;
    temp->next = NULL;
    return temp;
}

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node dummy;
    Node* cur = &dummy;
    dummy.next = NULL;
    int carry = 0;
    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) { sum += l1->val; l1 = l1->next; }
        if (l2) { sum += l2->val; l2 = l2->next; }
        carry = sum / 10;
        cur->next = newNode(sum % 10);
        cur = cur->next;
    }
    return dummy.next;
}

void printList(Node* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next) printf("->");
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* l1 = newNode(2);
    l1->next = newNode(4);
    l1->next->next = newNode(3);

    Node* l2 = newNode(5);
    l2->next = newNode(6);
    l2->next->next = newNode(4);

    Node* res = addTwoNumbers(l1, l2);
    printList(res);

    Node* l3 = newNode(0);
    Node* l4 = newNode(0);
    res = addTwoNumbers(l3, l4);
    printList(res);

    Node* l5 = newNode(9);
    l5->next = newNode(9);
    l5->next->next = newNode(9);
    l5->next->next->next = newNode(9);
    l5->next->next->next->next = newNode(9);
    l5->next->next->next->next->next = newNode(9);
    l5->next->next->next->next->next->next = newNode(9);

    Node* l6 = newNode(9);
    l6->next = newNode(9);
    l6->next->next = newNode(9);
    l6->next->next->next = newNode(9);

    res = addTwoNumbers(l5, l6);
    printList(res);

    return 0;
}