#include <stdio.h>

int heap[1000];
int size = 0;

void insert(int x) {
    int i = size++;
    while (i > 0 && heap[(i - 1) / 2] > x) {
        heap[i] = heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap[i] = x;
}

int extractMin() {
    if (size == 0) return -1;
    int root = heap[0];
    int last = heap[--size];
    int i = 0, child;
    while (2 * i + 1 < size) {
        child = 2 * i + 1;
        if (child + 1 < size && heap[child + 1] < heap[child])
            child++;
        if (last <= heap[child]) break;
        heap[i] = heap[child];
        i = child;
    }
    heap[i] = last;
    return root;
}

int peek() {
    if (size == 0) return -1;
    return heap[0];
}

int main() {
    int n, x;
    char op[20];
    scanf("%d", &n);
    while (n--) {
        scanf("%s", op);
        if (op[0] == 'i') {
            scanf("%d", &x);
            insert(x);
        } else if (op[0] == 'e') {
            printf("%d\n", extractMin());
        } else if (op[0] == 'p') {
            printf("%d\n", peek());
        }
    }
    return 0;
}