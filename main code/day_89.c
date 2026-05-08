#include <stdio.h>

int isPossible(int weights[], int n, int days, int capacity)
{
    int dayCount = 1;
    int total = 0;

    for(int i = 0; i < n; i++)
    {
        if(weights[i] > capacity)
            return 0;

        if(total + weights[i] > capacity)
        {
            dayCount++;
            total = weights[i];

            if(dayCount > days)
                return 0;
        }
        else
        {
            total += weights[i];
        }
    }

    return 1;
}

int shipWithinDays(int weights[], int n, int days)
{
    int low = 0;
    int high = 0;
    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        high += weights[i];
    }

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(isPossible(weights, n, days, mid))
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
    int n, days;

    scanf("%d %d", &n, &days);

    int weights[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &weights[i]);
    }

    printf("%d", shipWithinDays(weights, n, days));

    return 0;
}