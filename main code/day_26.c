#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return -1;
    Node *cur = obj->head;
    for (int i = 0; i < index; i++) cur = cur->next;
    return cur->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = obj->head;
    obj->head = node;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    if (!obj->head) obj->head = node;
    else {
        Node *cur = obj->head;
        while (cur->next) cur = cur->next;
        cur->next = node;
    }
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size) return;
    if (index == 0) { myLinkedListAddAtHead(obj, val); return; }
    Node *node = (Node*)malloc(sizeof(Node));
    node->val = val;
    Node *cur = obj->head;
    for (int i = 0; i < index - 1; i++) cur = cur->next;
    node->next = cur->next;
    cur->next = node;
    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return;
    Node *cur = obj->head;
    if (index == 0) {
        obj->head = cur->next;
        free(cur);
    } else {
        for (int i = 0; i < index - 1; i++) cur = cur->next;
        Node *tmp = cur->next;
        cur->next = tmp->next;
        free(tmp);
    }
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    Node *cur = obj->head;
    while (cur) {
        Node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(obj);
}

int main() {
    MyLinkedList* myLinkedList = myLinkedListCreate();
    myLinkedListAddAtHead(myLinkedList, 1);
    myLinkedListAddAtTail(myLinkedList, 3);
    myLinkedListAddAtIndex(myLinkedList, 1, 2);
    printf("%d\n", myLinkedListGet(myLinkedList, 1));
    myLinkedListDeleteAtIndex(myLinkedList, 1);
    printf("%d\n", myLinkedListGet(myLinkedList, 1));
    myLinkedListFree(myLinkedList);
    return 0;
}