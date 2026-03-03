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

typedef struct Stack {
    int arr[200];
    int top;
} Stack;

void push(Stack* s, int val) {
    s->arr[++s->top] = val;
}

int pop(Stack* s) {
    return s->arr[s->top--];
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

Node* addTwoNumbers(Node* l1, Node* l2) {
    Stack s1, s2;
    s1.top = s2.top = -1;
    while (l1) { push(&s1, l1->val); l1 = l1->next; }
    while (l2) { push(&s2, l2->val); l2 = l2->next; }
    int carry = 0;
    Node* head = NULL;
    while (!isEmpty(&s1) || !isEmpty(&s2) || carry) {
        int sum = carry;
        if (!isEmpty(&s1)) sum += pop(&s1);
        if (!isEmpty(&s2)) sum += pop(&s2);
        Node* node = newNode(sum % 10);
        node->next = head;
        head = node;
        carry = sum / 10;
    }
    return head;
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
    Node* l1 = newNode(7);
    l1->next = newNode(2);
    l1->next->next = newNode(4);
    l1->next->next->next = newNode(3);

    Node* l2 = newNode(5);
    l2->next = newNode(6);
    l2->next->next = newNode(4);

    Node* res = addTwoNumbers(l1, l2);
    printList(res);

    Node* l3 = newNode(2);
    l3->next = newNode(4);
    l3->next->next = newNode(3);

    Node* l4 = newNode(5);
    l4->next = newNode(6);
    l4->next->next = newNode(4);

    res = addTwoNumbers(l3, l4);
    printList(res);

    Node* l5 = newNode(0);
    Node* l6 = newNode(0);
    res = addTwoNumbers(l5, l6);
    printList(res);

    return 0;
}