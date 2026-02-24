#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    while (n % 2 == 0) {
        n = n / 2;
    }
    return n == 1;
}

int main() {
    int n;
    scanf("%d", &n);
    if (isPowerOfTwo(n))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}