#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    char tasks[n];
    for (int i = 0; i < n; i++)
        scanf(" %c", &tasks[i]);

    int cool;
    scanf("%d", &cool);

    int freq[26] = {0};

    for (int i = 0; i < n; i++)
        freq[tasks[i] - 'A']++;

    int maxFreq = 0;
    for (int i = 0; i < 26; i++)
        if (freq[i] > maxFreq)
            maxFreq = freq[i];

    int countMax = 0;
    for (int i = 0; i < 26; i++)
        if (freq[i] == maxFreq)
            countMax++;

    int partCount = maxFreq - 1;
    int partLength = cool - (countMax - 1);
    if (partLength < 0) partLength = 0;

    int emptySlots = partCount * partLength;
    int availableTasks = n - maxFreq * countMax;
    int idles = emptySlots - availableTasks;
    if (idles < 0) idles = 0;

    printf("%d\n", n + idles);

    return 0;
}