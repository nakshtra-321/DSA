#include <stdio.h>

int isPossible(int arr[], int n, int k, int maxTime)
{
    int painters = 1;
    int total = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > maxTime)
            return 0;

        if(total + arr[i] > maxTime)
        {
            painters++;
            total = arr[i];

            if(painters > k)
                return 0;
        }
        else
        {
            total += arr[i];
        }
    }

    return 1;
}

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);

    int arr[n];

    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    int low = 0;
    int high = sum;
    int ans = 0;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(isPossible(arr, n, k, mid))
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