#include <stdio.h>
#include <string.h>

void reverseString(char s[], int sSize) {
    int start = 0, end = sSize - 1;
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char s[] = {'h', 'e', 'l', 'l', 'o'};
    int n = sizeof(s) / sizeof(s[0]);
    
    reverseString(s, n);

    printf("Reversed string: [");
    for (int i = 0; i < n; i++) {
        printf("\"%c\"", s[i]);
        if (i < n - 1) printf(",");
    }
    printf("]\n");

    return 0;
}