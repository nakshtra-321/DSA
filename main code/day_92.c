#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low;

    for(int j = low; j < high; j++)
    {
        if(arr[j] > pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);

    return i;
}

int quickSelect(int arr[], int low, int high, int k)
{
    if(low <= high)
    {
        int pi = partition(arr, low, high);

        if(pi == k - 1)
            return arr[pi];

        else if(pi > k - 1)
            return quickSelect(arr, low, pi - 1, k);

        else
            return quickSelect(arr, pi + 1, high, k);
    }

    return -1;
}

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);

    int arr[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("%d", quickSelect(arr, 0, n - 1, k));

    return 0;
}