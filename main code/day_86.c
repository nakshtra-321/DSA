#include <stdio.h>

int mySqrt(int x) {
    long left = 0, right = x, ans = 0;
    
    while (left <= right) {
        long mid = left + (right - left) / 2;
        
        if (mid * mid <= x) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return (int)ans;
}

int main() {
    int x;
    scanf("%d", &x);
    
    int result = mySqrt(x);
    printf("%d", result);
    
    return 0;
}