#include <stdio.h>
#include <string.h>
#define MAX_CHAR 26
char firstRepeatedCharacter(char *s) {
    int count[MAX_CHAR] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';
        count[index]++;
        if (count[index] == 2) {
            return s[i];
        }
    }
    return -1; // No repeated character
}
int main() {
    char s[100];
    scanf("%s", s);
    char result = firstRepeatedCharacter(s);
    if (result != -1) {
        printf("%c\n", result);
    } else {
        printf("-1\n");
    }
    return 0;
}
