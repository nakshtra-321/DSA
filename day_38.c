#include <stdio.h>
#include <string.h>
#define MAX 1000

int dq[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int size() {
    if (isEmpty()) return 0;
    return rear - front + 1;
}

void push_front(int x) {
    if (front == -1) {
        front = rear = 0;
    } else if (front > 0) {
        dq[--front] = x;
    }
}

void push_back(int x) {
    if (front == -1) {
        front = rear = 0;
    } else {
        dq[++rear] = x;
    }
}

int pop_front() {
    if (isEmpty()) return -1;
    int val = dq[front];
    if (front == rear) front = rear = -1;
    else front++;
    return val;
}

int pop_back() {
    if (isEmpty()) return -1;
    int val = dq[rear];
    if (front == rear) front = rear = -1;
    else rear--;
    return val;
}

int get_front() {
    if (isEmpty()) return -1;
    return dq[front];
}

int get_back() {
    if (isEmpty()) return -1;
    return dq[rear];
}

void clear() {
    front = rear = -1;
}

void reverse() {
    if (isEmpty()) return;
    int i = front, j = rear;
    while (i < j) {
        int t = dq[i];
        dq[i] = dq[j];
        dq[j] = t;
        i++;
        j--;
    }
}

void sort() {
    int n = size();
    for (int i = front; i <= rear; i++) {
        for (int j = i + 1; j <= rear; j++) {
            if (dq[i] > dq[j]) {
                int t = dq[i];
                dq[i] = dq[j];
                dq[j] = t;
            }
        }
    }
}

int main() {
    int n, x;
    char op[20];
    scanf("%d", &n);
    while (n--) {
        scanf("%s", op);
        if (strcmp(op, "push_front") == 0) {
            scanf("%d", &x);
            push_front(x);
        } else if (strcmp(op, "push_back") == 0) {
            scanf("%d", &x);
            push_back(x);
        } else if (strcmp(op, "pop_front") == 0) {
            printf("%d\n", pop_front());
        } else if (strcmp(op, "pop_back") == 0) {
            printf("%d\n", pop_back());
        } else if (strcmp(op, "front") == 0) {
            printf("%d\n", get_front());
        } else if (strcmp(op, "back") == 0) {
            printf("%d\n", get_back());
        } else if (strcmp(op, "size") == 0) {
            printf("%d\n", size());
        } else if (strcmp(op, "empty") == 0) {
            printf("%d\n", isEmpty());
        } else if (strcmp(op, "clear") == 0) {
            clear();
        } else if (strcmp(op, "reverse") == 0) {
            reverse();
        } else if (strcmp(op, "sort") == 0) {
            sort();
        }
    }
    return 0;
}