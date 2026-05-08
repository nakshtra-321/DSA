#include <stdio.h>

long long merge(int arr[], int low, int mid, int high)
{
    int temp[100000];

    int i = low;
    int j = mid + 1;
    int k = low;

    long long count = 0;

    while(i <= mid && j <= high)
    {
        if(arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];

            count += (mid - i + 1);
        }
    }

    while(i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while(j <= high)
    {
        temp[k++] = arr[j++];
    }

    for(i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }

    return count;
}

long long mergeSort(int arr[], int low, int high)
{
    long long count = 0;

    if(low < high)
    {
        int mid = (low + high) / 2;

        count += mergeSort(arr, low, mid);

        count += mergeSort(arr, mid + 1, high);

        count += merge(arr, low, mid, high);
    }

    return count;
}

int main()
{
    int n;

    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("%lld", mergeSort(arr, 0, n - 1));

    return 0;
}