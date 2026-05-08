#include <stdio.h>

int merge(int arr[], int low, int mid, int high)
{
    int count = 0;

    int j = mid + 1;

    for(int i = low; i <= mid; i++)
    {
        while(j <= high && (long long)arr[i] > 2LL * arr[j])
        {
            j++;
        }

        count += (j - (mid + 1));
    }

    int temp[100000];

    int i = low;
    j = mid + 1;
    int k = low;

    while(i <= mid && j <= high)
    {
        if(arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
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

int mergeSort(int arr[], int low, int high)
{
    int count = 0;

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

    printf("%d", mergeSort(arr, 0, n - 1));

    return 0;
}