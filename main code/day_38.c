#include <stdio.h>

int dq[100000];
int front = 0, rear = -1;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int nums[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    for (int i = 0; i < n; i++) {
        if (front <= rear && dq[front] <= i - k)
            front++;

        while (front <= rear && nums[dq[rear]] <= nums[i])
            rear--;

        dq[++rear] = i;

        if (i >= k - 1)
            printf("%d ", nums[dq[front]]);
    }

    return 0;
}