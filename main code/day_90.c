#include <stdio.h>

int isPossible(int nums[], int n, int k, int maxSum)
{
    int count = 1;
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        if(nums[i] > maxSum)
            return 0;

        if(sum + nums[i] > maxSum)
        {
            count++;
            sum = nums[i];

            if(count > k)
                return 0;
        }
        else
        {
            sum += nums[i];
        }
    }

    return 1;
}

int splitArray(int nums[], int n, int k)
{
    int low = 0;
    int high = 0;
    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        high += nums[i];
    }

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(isPossible(nums, n, k, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);

    int nums[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    printf("%d", splitArray(nums, n, k));

    return 0;
}