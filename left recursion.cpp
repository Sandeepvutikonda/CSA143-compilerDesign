#include <stdio.h>
#include <string.h>

void eliminateLeftRecursion(char nonTerminal, char production[][10], int numProductions) {
    int i, j;

    printf("\nAfter Eliminating Left Recursion:\n");

    for (i = 0; i < numProductions; i++) {
        if (production[i][0] == nonTerminal) {
            char alpha[10][10], beta[10][10];
            int alphaCount = 0, betaCount = 0;

            for (j = 3; j < strlen(production[i]); j++) {
                if (production[i][j] == '|') {
                    beta[betaCount][0] = '\0';
                    betaCount++;
                    continue;
                }

                if (production[i][j] == nonTerminal) {
                    strcpy(alpha[alphaCount], &production[i][j + 1]);
                    alphaCount++;
                } else {
                    strcpy(beta[betaCount], &production[i][j]);
                    betaCount++;
                    break;
                }
            }

            printf("%c' -> epsilon | ", nonTerminal);
            for (j = 0; j < betaCount; j++) {
                printf("%s%c'|", beta[j], nonTerminal);
            }
            printf("\b \n");

            printf("%c -> ", nonTerminal);
            for (j = 0; j < alphaCount; j++) {
                printf("%s%c'|", alpha[j], nonTerminal);
            }
            printf("\b \n");
        } else {
            printf("%c -> %s\n", nonTerminal, production[i]);
        }
    }
}

int main() {
    char nonTerminal;
    char production[10][10];
    int numProductions;

    printf("Enter the non-terminal: ");
    scanf(" %c", &nonTerminal);

    printf("Enter the number of productions: ");
    scanf("%d", &numProductions);

    printf("Enter the productions:\n");
    for (int i = 0; i < numProductions; i++) {
        scanf("%s", production[i]);
    }

    eliminateLeftRecursion(nonTerminal, production, numProductions);

    return 0;
}
