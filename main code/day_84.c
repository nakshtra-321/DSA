#include <stdio.h>

int findPeak(int arr[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > arr[mid + 1])
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    int peakIndex = findPeak(arr, n);
    printf("%d", peakIndex);
    
    return 0;
}