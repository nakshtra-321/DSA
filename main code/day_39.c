#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num, freq;
} Pair;

int cmp(const void *a, const void *b) {
    return ((Pair*)b)->freq - ((Pair*)a)->freq;
}

int main() {
    int n, k;
    scanf("%d", &n);
    int nums[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    scanf("%d", &k);

    Pair arr[200001];
    int offset = 100000;

    for (int i = 0; i < 200001; i++) {
        arr[i].num = i - offset;
        arr[i].freq = 0;
    }

    for (int i = 0; i < n; i++)
        arr[nums[i] + offset].freq++;

    qsort(arr, 200001, sizeof(Pair), cmp);

    int count = 0;
    for (int i = 0; i < 200001 && count < k; i++) {
        if (arr[i].freq > 0) {
            printf("%d ", arr[i].num);
            count++;
        }
    }

    return 0;
}