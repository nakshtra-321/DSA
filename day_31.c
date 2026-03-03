#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main() {
    int stack[MAX], top = -1;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int op, val;
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &val);
            if (top < MAX - 1) stack[++top] = val;
        } else if (op == 2) {
            if (top == -1) printf("Stack Underflow\n");
            else printf("%d\n", stack[top--]);
        } else if (op == 3) {
            if (top == -1) continue;
            for (int j = top; j >= 0; j--) {
                printf("%d", stack[j]);
                if (j != 0) printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}