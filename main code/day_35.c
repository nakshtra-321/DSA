#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void init(Stack *s){
    s->top = -1;
}

int isEmpty(Stack *s){
    return s->top == -1;
}

void pushStack(Stack *s, int x){
    s->arr[++(s->top)] = x;
}

int popStack(Stack *s){
    return s->arr[(s->top)--];
}

int peekStack(Stack *s){
    return s->arr[s->top];
}

typedef struct {
    Stack s1;
    Stack s2;
} MyQueue;

void initQueue(MyQueue *q){
    init(&q->s1);
    init(&q->s2);
}

void push(MyQueue *q, int x){
    pushStack(&q->s1, x);
}

void transfer(MyQueue *q){
    while(!isEmpty(&q->s1)){
        pushStack(&q->s2, popStack(&q->s1));
    }
}

int pop(MyQueue *q){
    if(isEmpty(&q->s2)){
        transfer(q);
    }
    return popStack(&q->s2);
}

int peek(MyQueue *q){
    if(isEmpty(&q->s2)){
        transfer(q);
    }
    return peekStack(&q->s2);
}

int empty(MyQueue *q){
    return isEmpty(&q->s1) && isEmpty(&q->s2);
}

int main(){
    MyQueue q;
    initQueue(&q);

    push(&q,1);
    push(&q,2);

    printf("%d\n",peek(&q));
    printf("%d\n",pop(&q));
    printf("%d\n",empty(&q));

    return 0;
}