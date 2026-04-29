#include <stdio.h>

int main() {
    long n;
    scanf("%ld", &n);

    long left = 0, right = n, ans = 0;

    while (left <= right) {
        long mid = left + (right - left) / 2;

        if (mid * mid <= n) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("%ld", ans);

    return 0;
}