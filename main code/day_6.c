#include <stdio.h>

void moveZeroes(int nums[], int n) {
    int pos = 0; 
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            nums[pos] = nums[i];
            pos++;
        }
    }
    while (pos < n) {
        nums[pos] = 0;
        pos++;
    }
}

int main() {
    int nums[] = {0, 1, 0, 3, 12};
    int n = sizeof(nums) / sizeof(nums[0]);

    moveZeroes(nums, n);

    printf("Output: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    printf("\n");
    return 0;
}