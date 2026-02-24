#include <stdio.h>
#include <stdlib.h>

// Structure for prefix-sum map
typedef struct Node {
    int key;           // prefix sum
    int freq;          // frequency
    struct Node* next; // linked list for collisions
} Node;

#define SIZE 1009  // hash table size (prime number)

int hash(int key) {
    if (key < 0) key = -key;
    return key % SIZE;
}

void insert(Node* hashTable[], int key) {
    int idx = hash(key);
    Node* temp = hashTable[idx];
    while (temp) {
        if (temp->key == key) {
            temp->freq++;
            return;
        }
        temp = temp->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->freq = 1;
    newNode->next = hashTable[idx];
    hashTable[idx] = newNode;
}

int getFreq(Node* hashTable[], int key) {
    int idx = hash(key);
    Node* temp = hashTable[idx];
    while (temp) {
        if (temp->key == key)
            return temp->freq;
        temp = temp->next;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    Node* hashTable[SIZE] = {NULL};
    int sum = 0, count = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: Subarray (0...i) has sum 0
        if (sum == 0)
            count++;

        // Case 2: sum has been seen before → add its frequency
        count += getFreq(hashTable, sum);

        // Update frequency of current prefix sum
        insert(hashTable, sum);
    }

    printf("%d\n", count);
    return 0;
}