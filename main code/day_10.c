#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int intersection(int nums1[], int n1, int nums2[], int n2, int result[]) {
    qsort(nums1, n1, sizeof(int), compare);
    qsort(nums2, n2, sizeof(int), compare);

    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (nums1[i] == nums2[j]) {
            result[k++] = nums1[i];
            i++;
            j++;
        } else if (nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }

    return k;
}

int main() {
    int nums1[] = {1, 2, 2, 1};
    int nums2[] = {2, 2};

    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    int n2 = sizeof(nums2) / sizeof(nums2[0]);

    int result[n1 < n2 ? n1 : n2]; 

    int size = intersection(nums1, n1, nums2, n2, result);

    printf("Output = [");
    for (int i = 0; i < size; i++) {
        printf("%d", result[i]);
        if (i < size - 1) printf(",");
    }
    printf("]\n");

    return 0;
}