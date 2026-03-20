#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int temp[n], ans[n], stack[n];
    int top = -1;

    for (int i = 0; i < n; i++) {
        scanf("%d", &temp[i]);
        ans[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        while (top != -1 && temp[i] > temp[stack[top]]) {
            int idx = stack[top--];
            ans[idx] = i - idx;
        }
        stack[++top] = i;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);

    return 0;
}