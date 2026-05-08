#include <stdio.h>

void insertionSort(float bucket[], int n)
{
    for(int i = 1; i < n; i++)
    {
        float key = bucket[i];
        int j = i - 1;

        while(j >= 0 && bucket[j] > key)
        {
            bucket[j + 1] = bucket[j];
            j--;
        }

        bucket[j + 1] = key;
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    float arr[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }

    float buckets[n][n];
    int count[n];

    for(int i = 0; i < n; i++)
    {
        count[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        int index = arr[i] * n;

        buckets[index][count[index]] = arr[i];
        count[index]++;
    }

    for(int i = 0; i < n; i++)
    {
        insertionSort(buckets[i], count[i]);
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < count[i]; j++)
        {
            printf("%.2f ", buckets[i][j]);
        }
    }

    return 0;
}