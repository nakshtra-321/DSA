#include <stdio.h>

int main() {
    int n, pos;
    
    // Input number of elements
    scanf("%d", &n);
    
    int arr[100]; // assuming max size 100
    
    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input position to delete (1-based)
    scanf("%d", &pos);
    
    // Validate position
    if (pos < 1 || pos > n) {
        printf("Invalid position");
        return 0;
    }
    
    // Shift elements left to overwrite deleted element
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    n--; // array size decreases by 1
    
    // Print updated array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
