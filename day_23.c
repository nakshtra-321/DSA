#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// Create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Detect cycle using Floyd's Algorithm
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;           // move 1 step
        fast = fast->next->next;     // move 2 steps
        if (slow == fast) {          // meet → cycle found
            return true;
        }
    }

    return false; // no cycle
}

// Example usage
int main() {
    // Create nodes
    struct ListNode* head = createNode(3);
    struct ListNode* second = createNode(2);
    struct ListNode* third = createNode(0);
    struct ListNode* fourth = createNode(-4);

    // Link nodes: 3 -> 2 -> 0 -> -4
    head->next = second;
    second->next = third;
    third->next = fourth;
    
    // Create a cycle: tail connects to node with value 2
    fourth->next = second;  

    // Check for cycle
    if (hasCycle(head))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}