#include <stdio.h>
#include <stdlib.h>

struct Car
{
    int position;
    int speed;
};

int compare(const void *a, const void *b)
{
    struct Car *x = (struct Car*)a;
    struct Car *y = (struct Car*)b;

    return y->position - x->position;
}

int main()
{
    int target, n;

    scanf("%d %d", &target, &n);

    struct Car cars[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &cars[i].position);
    }

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &cars[i].speed);
    }

    qsort(cars, n, sizeof(struct Car), compare);

    double time[n];

    for(int i = 0; i < n; i++)
    {
        time[i] = (double)(target - cars[i].position) / cars[i].speed;
    }

    int fleets = 0;
    double maxTime = 0;

    for(int i = 0; i < n; i++)
    {
        if(time[i] > maxTime)
        {
            fleets++;
            maxTime = time[i];
        }
    }

    printf("%d", fleets);

    return 0;
}