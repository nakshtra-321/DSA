#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool removeCycle(Node* head) {
    if (!head || !head->next) return false;
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    if (slow != fast) return false;
    slow = head;
    if (slow == fast) {
        while (fast->next != slow) fast = fast->next;
    } else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    fast->next = NULL;
    return true;
}

int main() {
    Node* head = newNode(1);
    head->next = newNode(3);
    head->next->next = newNode(4);
    head->next->next->next = head->next; 
    bool res = removeCycle(head);
    printf(res ? "true\n" : "false\n");

    Node* head2 = newNode(1);
    head2->next = newNode(8);
    head2->next->next = newNode(3);
    head2->next->next->next = newNode(4);
    res = removeCycle(head2);
    printf(res ? "true\n" : "false\n");

    Node* head3 = newNode(1);
    head3->next = newNode(2);
    head3->next->next = newNode(3);
    head3->next->next->next = newNode(4);
    head3->next->next->next->next = head3;
    res = removeCycle(head3);
    printf(res ? "true\n" : "false\n");
    return 0;
}