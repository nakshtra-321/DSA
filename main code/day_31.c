#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char *s) {
    char stack[10000];
    int top = -1;
    for (int i = 0; s[i]; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{')
            stack[++top] = c;
        else {
            if (top == -1) return false;
            char t = stack[top--];
            if ((c == ')' && t != '(') ||
                (c == ']' && t != '[') ||
                (c == '}' && t != '{'))
                return false;
        }
    }
    return top == -1;
}

int main() {
    char s[10000];
    scanf("%s", s);
    printf(isValid(s) ? "true\n" : "false\n");
    return 0;
}