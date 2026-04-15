#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100
#define EMPTY -1

int hashTable[MAX_SIZE];
void initializeHashTable() {
    for (int i = 0; i < MAX_SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}
int hashFunction(int key) {
    return key % MAX_SIZE;
}
void insert(int key) {
    int hashIndex = hashFunction(key);
    int i = 0;
    while (hashTable[hashIndex] != EMPTY) {
        i++;
        hashIndex = (hashFunction(key) + i * i) % MAX_SIZE;
    }
    hashTable[hashIndex] = key;
}
int search(int key) {
    int hashIndex = hashFunction(key);
    int i = 0;
    while (hashTable[hashIndex] != EMPTY) {
        if (hashTable[hashIndex] == key) {
            return 1; // FOUND
        }
        i++;
        hashIndex = (hashFunction(key) + i * i) % MAX_SIZE;
    }
    return 0; // NOT FOUND
}
int main() {
    int n;
    scanf("%d", &n);
    initializeHashTable();

    for (int i = 0; i < n; i++) {
        char operation[10];
        int key;
        scanf("%s %d", operation, &key);

        if (strcmp(operation, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(operation, "SEARCH") == 0) {
            if (search(key)) {
                printf("FOUND\n");
            } else {
                printf("NOT FOUND\n");
            }
        }
    }
    return 0;
}