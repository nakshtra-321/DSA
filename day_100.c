#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    int index;
};

void merge(struct Node arr[], int low, int mid, int high, int count[])
{
    struct Node temp[100000];

    int i = low;
    int j = mid + 1;
    int k = low;

    int rightCount = 0;

    while(i <= mid && j <= high)
    {
        if(arr[j].value < arr[i].value)
        {
            temp[k++] = arr[j++];
            rightCount++;
        }
        else
        {
            count[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while(i <= mid)
    {
        count[arr[i].index] += rightCount;
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
}

void mergeSort(struct Node arr[], int low, int high, int count[])
{
    if(low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid, count);

        mergeSort(arr, mid + 1, high, count);

        merge(arr, low, mid, high, count);
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    struct Node arr[n];

    int count[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].value);

        arr[i].index = i;

        count[i] = 0;
    }

    mergeSort(arr, 0, n - 1, count);

    for(int i = 0; i < n; i++)
    {
        printf("%d ", count[i]);
    }

    return 0;
}