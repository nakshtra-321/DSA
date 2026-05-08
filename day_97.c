#include <stdio.h>
#include <stdlib.h>

struct Meeting
{
    int start;
    int end;
};

int compare(const void *a, const void *b)
{
    struct Meeting *x = (struct Meeting*)a;
    struct Meeting *y = (struct Meeting*)b;

    return x->start - y->start;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int index)
{
    while(index > 0)
    {
        int parent = (index - 1) / 2;

        if(heap[parent] > heap[index])
        {
            swap(&heap[parent], &heap[index]);
            index = parent;
        }
        else
        {
            break;
        }
    }
}

void heapifyDown(int heap[], int size, int index)
{
    while(1)
    {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if(left < size && heap[left] < heap[smallest])
        {
            smallest = left;
        }

        if(right < size && heap[right] < heap[smallest])
        {
            smallest = right;
        }

        if(smallest != index)
        {
            swap(&heap[smallest], &heap[index]);
            index = smallest;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    struct Meeting arr[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(struct Meeting), compare);

    int heap[n];
    int size = 0;

    heap[size++] = arr[0].end;

    int maxRooms = 1;

    for(int i = 1; i < n; i++)
    {
        if(arr[i].start >= heap[0])
        {
            heap[0] = arr[i].end;
            heapifyDown(heap, size, 0);
        }
        else
        {
            heap[size] = arr[i].end;
            heapifyUp(heap, size);
            size++;
        }

        if(size > maxRooms)
        {
            maxRooms = size;
        }
    }

    printf("%d", maxRooms);

    return 0;
}