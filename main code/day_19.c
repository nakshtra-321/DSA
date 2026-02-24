#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int totalSum = 0;
    int currentMax = nums[0], maxSum = nums[0];
    int currentMin = nums[0], minSum = nums[0];

    for (int i = 0; i < n; i++) {
        totalSum += nums[i];

        // Kadane's for max subarray
        if (i > 0)
            currentMax = max(nums[i], currentMax + nums[i]);
        maxSum = max(maxSum, currentMax);

        // Kadane's for min subarray
        if (i > 0)
            currentMin = min(nums[i], currentMin + nums[i]);
        minSum = min(minSum, currentMin);
    }

    // If all elements are negative
    if (maxSum < 0) {
        printf("%d\n", maxSum);
        return 0;
    }

    int circularSum = totalSum - minSum;
    printf("%d\n", max(maxSum, circularSum));

    return 0;
}