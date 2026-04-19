#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    int size;
    struct Node** neighbors;
};

struct Node* map[105];

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->size = 0;
    node->neighbors = (struct Node**)malloc(105 * sizeof(struct Node*));
    return node;
}

struct Node* cloneGraph(struct Node* node) {
    if(node == NULL) return NULL;
    if(map[node->val] != NULL) return map[node->val];

    struct Node* clone = createNode(node->val);
    map[node->val] = clone;

    for(int i = 0; i < node->size; i++) {
        clone->neighbors[clone->size++] = cloneGraph(node->neighbors[i]);
    }

    return clone;
}

int main() {
    return 0;
}