#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    int n, m;

    scanf("%d", &n);

    int arr1[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }

    scanf("%d", &m);

    int arr2[m];

    for(int i = 0; i < m; i++)
    {
        scanf("%d", &arr2[i]);
    }

    int freq[1001] = {0};

    for(int i = 0; i < n; i++)
    {
        freq[arr1[i]]++;
    }

    int result[n];
    int index = 0;

    for(int i = 0; i < m; i++)
    {
        while(freq[arr2[i]] > 0)
        {
            result[index++] = arr2[i];
            freq[arr2[i]]--;
        }
    }

    int remaining[n];
    int k = 0;

    for(int i = 0; i <= 1000; i++)
    {
        while(freq[i] > 0)
        {
            remaining[k++] = i;
            freq[i]--;
        }
    }

    qsort(remaining, k, sizeof(int), compare);

    for(int i = 0; i < k; i++)
    {
        result[index++] = remaining[i];
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ", result[i]);
    }

    return 0;
}