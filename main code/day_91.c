#include <stdio.h>

int possible(int arr[], int n, int k, int limit)
{
    int count = 1;
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > limit)
            return 0;

        if(sum + arr[i] > limit)
        {
            count++;
            sum = arr[i];

            if(count > k)
                return 0;
        }
        else
        {
            sum += arr[i];
        }
    }

    return 1;
}

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);

    int arr[n];

    int low = 0;
    int high = 0;
    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);

        high += arr[i];
    }

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(possible(arr, n, k, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}