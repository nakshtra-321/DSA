#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to print linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to merge two sorted linked lists
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    // Dummy node to simplify logic
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    // Traverse both lists
    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes
    if (l1 != NULL)
        tail->next = l1;
    else
        tail->next = l2;

    return dummy.next; // Head of merged list
}

int main() {
    int n, m, value;
    struct Node *head1 = NULL, *head2 = NULL;
    struct Node *temp = NULL, *newNode = NULL;

    // Input for first list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        newNode = createNode(value);
        if (head1 == NULL) {
            head1 = newNode;
            temp = head1;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    // Input for second list
    scanf("%d", &m);
    temp = NULL;
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        newNode = createNode(value);
        if (head2 == NULL) {
            head2 = newNode;
            temp = head2;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    // Merge two sorted lists
    struct Node* mergedHead = mergeLists(head1, head2);

    // Print merged list
    printList(mergedHead);

    return 0;
}