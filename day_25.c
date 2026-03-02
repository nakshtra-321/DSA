#include <stdio.h>
#include <stdlib.h>

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

// Function to detect the start of the cycle
struct ListNode* detectCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Phase 1: Detect if cycle exists
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Phase 2: Find the entry point of cycle
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;  // starting node of cycle
        }
    }

    return NULL;  // no cycle
}

int main() {
    // Example 1: head = [3,2,0,-4], pos = 1
    struct ListNode* head = createNode(3);
    struct ListNode* second = createNode(2);
    struct ListNode* third = createNode(0);
    struct ListNode* fourth = createNode(-4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second; // create cycle (pos = 1)

    struct ListNode* start = detectCycle(head);

    if (start != NULL)
        printf("Tail connects to node with value %d\n", start->val);
    else
        printf("No cycle detected\n");

    return 0;
}