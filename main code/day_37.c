#include <stdio.h>

int heap[10005];
int size = 0, k;

void heapify_up(int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        int t = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = t;
        i = (i - 1) / 2;
    }
}

void heapify_down(int i) {
    int smallest = i;
    while (1) {
        int l = 2*i + 1;
        int r = 2*i + 2;
        smallest = i;

        if (l < size && heap[l] < heap[smallest])
            smallest = l;
        if (r < size && heap[r] < heap[smallest])
            smallest = r;

        if (smallest != i) {
            int t = heap[i];
            heap[i] = heap[smallest];
            heap[smallest] = t;
            i = smallest;
        } else break;
    }
}

void add_val(int val) {
    if (size < k) {
        heap[size] = val;
        heapify_up(size);
        size++;
    } else if (val > heap[0]) {
        heap[0] = val;
        heapify_down(0);
    }
}

int main() {
    int n, x;
    scanf("%d %d", &k, &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        add_val(x);
    }

    int q;
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &x);
        add_val(x);
        if (size < k) printf("-1\n");
        else printf("%d\n", heap[0]);
    }

    return 0;
}