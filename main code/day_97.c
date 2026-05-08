#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    int n;

    scanf("%d", &n);

    int start[n], end[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &start[i]);
    }

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &end[i]);
    }

    qsort(start, n, sizeof(int), compare);
    qsort(end, n, sizeof(int), compare);

    int rooms = 0;
    int maxRooms = 0;

    int i = 0, j = 0;

    while(i < n && j < n)
    {
        if(start[i] < end[j])
        {
            rooms++;

            if(rooms > maxRooms)
            {
                maxRooms = rooms;
            }

            i++;
        }
        else
        {
            rooms--;
            j++;
        }
    }

    printf("%d", maxRooms);

    return 0;
}