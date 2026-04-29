#include <stdio.h>

long hoursNeeded(int piles[], int n, int k) {
    long hours = 0;
    for (int i = 0; i < n; i++)
        hours += (piles[i] + k - 1) / k;
    return hours;
}

int minEatingSpeed(int piles[], int n, int h) {
    int left = 1, right = 0;
    
    for (int i = 0; i < n; i++)
        if (piles[i] > right)
            right = piles[i];
    
    int ans = right;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (hoursNeeded(piles, n, mid) <= h) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return ans;
}

int main() {
    int n, h;
    scanf("%d", &n);
    
    int piles[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &piles[i]);
    
    scanf("%d", &h);
    
    int result = minEatingSpeed(piles, n, h);
    printf("%d", result);
    
    return 0;
}