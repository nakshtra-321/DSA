#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* alienOrder(char** words, int wordsSize) {
    int adj[26][26] = {0};
    int indegree[26] = {0};
    int present[26] = {0};
    
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; words[i][j]; j++) {
            present[words[i][j] - 'a'] = 1;
        }
    }
    
    for (int i = 0; i < wordsSize - 1; i++) {
        char *w1 = words[i];
        char *w2 = words[i + 1];
        int len1 = strlen(w1), len2 = strlen(w2);
        int found = 0;
        
        for (int j = 0; j < len1 && j < len2; j++) {
            if (w1[j] != w2[j]) {
                if (!adj[w1[j]-'a'][w2[j]-'a']) {
                    adj[w1[j]-'a'][w2[j]-'a'] = 1;
                    indegree[w2[j]-'a']++;
                }
                found = 1;
                break;
            }
        }
        
        if (!found && len1 > len2) {
            char* res = (char*)malloc(1);
            res[0] = '\0';
            return res;
        }
    }
    
    int queue[26];
    int front = 0, rear = 0;
    
    for (int i = 0; i < 26; i++) {
        if (present[i] && indegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    
    char* result = (char*)malloc(27);
    int idx = 0;
    
    while (front < rear) {
        int u = queue[front++];
        result[idx++] = u + 'a';
        
        for (int v = 0; v < 26; v++) {
            if (adj[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }
    
    int total = 0;
    for (int i = 0; i < 26; i++) if (present[i]) total++;
    
    if (idx != total) {
        result[0] = '\0';
        return result;
    }
    
    result[idx] = '\0';
    return result;
}