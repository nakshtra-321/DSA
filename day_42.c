#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int queue[n], stack[n];
    int front = 0, rear = n - 1, top = -1;

    for (int i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    while (front <= rear)
        stack[++top] = queue[front++];

    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);

    return 0;
}