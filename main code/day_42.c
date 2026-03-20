#include <stdio.h>

int maxHeap[50000], minHeap[50000];
int maxSize = 0, minSize = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void maxHeapifyUp(int i) {
    while (i > 0 && maxHeap[(i - 1) / 2] < maxHeap[i]) {
        swap(&maxHeap[i], &maxHeap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void maxHeapifyDown(int i) {
    int largest = i;
    while (1) {
        int l = 2*i + 1, r = 2*i + 2;
        largest = i;

        if (l < maxSize && maxHeap[l] > maxHeap[largest])
            largest = l;
        if (r < maxSize && maxHeap[r] > maxHeap[largest])
            largest = r;

        if (largest != i) {
            swap(&maxHeap[i], &maxHeap[largest]);
            i = largest;
        } else break;
    }
}

void minHeapifyUp(int i) {
    while (i > 0 && minHeap[(i - 1) / 2] > minHeap[i]) {
        swap(&minHeap[i], &minHeap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void minHeapifyDown(int i) {
    int smallest = i;
    while (1) {
        int l = 2*i + 1, r = 2*i + 2;
        smallest = i;

        if (l < minSize && minHeap[l] < minHeap[smallest])
            smallest = l;
        if (r < minSize && minHeap[r] < minHeap[smallest])
            smallest = r;

        if (smallest != i) {
            swap(&minHeap[i], &minHeap[smallest]);
            i = smallest;
        } else break;
    }
}

void addNum(int num) {
    if (maxSize == 0 || num <= maxHeap[0]) {
        maxHeap[maxSize] = num;
        maxHeapifyUp(maxSize);
        maxSize++;
    } else {
        minHeap[minSize] = num;
        minHeapifyUp(minSize);
        minSize++;
    }

    if (maxSize > minSize + 1) {
        minHeap[minSize] = maxHeap[0];
        minHeapifyUp(minSize);
        minSize++;

        maxHeap[0] = maxHeap[--maxSize];
        maxHeapifyDown(0);
    } else if (minSize > maxSize) {
        maxHeap[maxSize] = minHeap[0];
        maxHeapifyUp(maxSize);
        maxSize++;

        minHeap[0] = minHeap[--minSize];
        minHeapifyDown(0);
    }
}

double findMedian() {
    if (maxSize > minSize)
        return maxHeap[0];
    return (maxHeap[0] + minHeap[0]) / 2.0;
}

int main() {
    int q, x;
    char op[20];
    scanf("%d", &q);

    while (q--) {
        scanf("%s", op);
        if (op[0] == 'a') {
            scanf("%d", &x);
            addNum(x);
        } else {
            printf("%.5f\n", findMedian());
        }
    }

    return 0;
}