#include <stdio.h>
#include <string.h>

// Recursive function to reverse the string in-place
void reverseString(char s[], int start, int end) {
    if (start >= end)
        return; // base case: done swapping

    // swap s[start] and s[end]
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;

    // recursive call for the next pair
    reverseString(s, start + 1, end - 1);
}

int main() {
    char s[100];
    scanf("%s", s); // read string (no spaces)

    int len = strlen(s);
    reverseString(s, 0, len - 1);

    printf("%s\n", s); // print mirrored string
    return 0;
}