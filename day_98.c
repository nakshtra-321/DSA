#include <stdio.h>
#include <stdlib.h>

struct Interval
{
    int start;
    int end;
};

int compare(const void *a, const void *b)
{
    struct Interval *x = (struct Interval*)a;
    struct Interval *y = (struct Interval*)b;

    return x->start - y->start;
}

int main()
{
    int n;

    scanf("%d", &n);

    struct Interval arr[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(struct Interval), compare);

    int start = arr[0].start;
    int end = arr[0].end;

    for(int i = 1; i < n; i++)
    {
        if(arr[i].start <= end)
        {
            if(arr[i].end > end)
            {
                end = arr[i].end;
            }
        }
        else
        {
            printf("[%d,%d] ", start, end);

            start = arr[i].start;
            end = arr[i].end;
        }
    }

    printf("[%d,%d]", start, end);

    return 0;
}