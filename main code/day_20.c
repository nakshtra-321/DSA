#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Step 1: Sort the array
    qsort(nums, n, sizeof(int), compare);

    printf("[");
    int firstTriplet = 1; // for formatting output

    // Step 2: Fix one number and use two-pointer technique
    for (int i = 0; i < n - 2; i++) {
        // Skip duplicate elements
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                if (!firstTriplet)
                    printf(",");
                printf("[%d,%d,%d]", nums[i], nums[left], nums[right]);
                firstTriplet = 0;

                // Move both pointers and skip duplicates
                int leftVal = nums[left];
                int rightVal = nums[right];
                while (left < right && nums[left] == leftVal) left++;
                while (left < right && nums[right] == rightVal) right--;
            }
            else if (sum < 0)
                left++;
            else
                right--;
        }
    }

    printf("]\n");
    return 0;
}