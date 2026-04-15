#include <stdio.h>
#include <string.h>
#define MAX_CHAR 26
char firstNonRepeatingCharacter(char *s) {
    int count[MAX_CHAR] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';
        count[index]++;
    }
    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';
        if (count[index] == 1) {
            return s[i];
        }
    }
    return '$'; // No non-repeating character
}
int main() {
    char s[100];
    scanf("%s", s);
    char result = firstNonRepeatingCharacter(s);
    printf("%c\n", result);
    return 0;
}
