#include <stdio.h>

int findMin(int arr[], int n) {
    int left = 0, right = n - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] > arr[right])
            left = mid + 1;
        else
            right = mid;
    }
    
    return arr[left];
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    int result = findMin(arr, n);
    printf("%d", result);
    
    return 0;
}