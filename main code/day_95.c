#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    int n;

    scanf("%d", &n);

    if(n < 2)
    {
        printf("0");
        return 0;
    }

    int nums[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    qsort(nums, n, sizeof(int), compare);

    int maxGap = 0;

    for(int i = 1; i < n; i++)
    {
        int diff = nums[i] - nums[i - 1];

        if(diff > maxGap)
        {
            maxGap = diff;
        }
    }

    printf("%d", maxGap);

    return 0;
}