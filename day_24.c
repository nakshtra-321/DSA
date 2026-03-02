#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to remove nodes with given value
struct ListNode* removeElements(struct ListNode* head, int val) {
    // Create dummy node to handle head removals
    struct ListNode* dummy = createNode(0);
    dummy->next = head;

    struct ListNode* prev = dummy;
    struct ListNode* curr = head;

    while (curr != NULL) {
        if (curr->val == val) {
            prev->next = curr->next; // skip current node
            free(curr); // free memory
        } else {
            prev = curr; // move prev if current not deleted
        }
        curr = prev->next; // move curr forward
    }

    head = dummy->next;
    free(dummy);
    return head;
}

// Helper function to print list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Example: head = [1,2,6,3,4,5,6], val = 6
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(6);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(5);
    head->next->next->next->next->next->next = createNode(6);

    int val = 6;

    printf("Original list: ");
    printList(head);

    head = removeElements(head, val);

    printf("After removing %d: ", val);
    printList(head);

    return 0;
}