#include <stdio.h>

#define MAX 30000

typedef struct {
    int stack[MAX];
    int minStack[MAX];
    int top;
} MinStack;

void MinStackInit(MinStack* obj) {
    obj->top = -1;
}

void push(MinStack* obj, int val) {
    obj->top++;
    obj->stack[obj->top] = val;
    if (obj->top == 0 || val <= obj->minStack[obj->top - 1])
        obj->minStack[obj->top] = val;
    else
        obj->minStack[obj->top] = obj->minStack[obj->top - 1];
}

void pop(MinStack* obj) {
    if (obj->top >= 0)
        obj->top--;
}

int top(MinStack* obj) {
    return obj->stack[obj->top];
}

int getMin(MinStack* obj) {
    return obj->minStack[obj->top];
}

int main() {
    MinStack s;
    MinStackInit(&s);

    push(&s, -2);
    push(&s, 0);
    push(&s, -3);

    printf("%d\n", getMin(&s));
    pop(&s);
    printf("%d\n", top(&s));
    printf("%d\n", getMin(&s));

    return 0;
}