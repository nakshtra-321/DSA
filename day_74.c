#include <stdio.h>
#include <string.h>
#define MAX_VOTES 100
#define MAX_NAME_LENGTH 100
void findWinner(char votes[MAX_VOTES][MAX_NAME_LENGTH], int n) {
    char winner[MAX_NAME_LENGTH];
    int maxVotes = 0;
    int count[MAX_VOTES] = {0};

    for (int i = 0; i < n; i++) {
        count[i] = 1; // Initialize count for each candidate
        for (int j = 0; j < i; j++) {
            if (strcmp(votes[i], votes[j]) == 0) {
                count[j]++;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, votes[i]);
        } else if (count[i] == maxVotes && strcmp(votes[i], winner) < 0) {
            strcpy(winner, votes[i]);
        }
    }

    printf("%s %d\n", winner, maxVotes);
}
int main() {
    int n;
    scanf("%d", &n);
    char votes[MAX_VOTES][MAX_NAME_LENGTH];

    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    findWinner(votes, n);
    return 0;
}