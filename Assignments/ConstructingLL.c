#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NON_TERMINALS 10
#define MAX_TERMINALS 10

int main() {
    int numNonTerminals, numTerminals;
    char nonTerminals[MAX_NON_TERMINALS][10];
    char terminals[MAX_TERMINALS][10];
    char parsingTable[MAX_NON_TERMINALS][MAX_TERMINALS][10];

    printf("Enter the number of non-terminals: ");
    scanf("%d", &numNonTerminals);

    printf("Enter the non-terminals:\n");
    for (int i = 0; i < numNonTerminals; i++) {
        scanf("%s", nonTerminals[i]);
    }

    printf("Enter the number of terminals: ");
    scanf("%d", &numTerminals);

    printf("Enter the terminals:\n");
    for (int i = 0; i < numTerminals; i++) {
        scanf("%s", terminals[i]);
    }

    printf("Enter the LL(1) parsing table:\n");
    for (int i = 0; i < numNonTerminals; i++) {
        for (int j = 0; j < numTerminals; j++) {
            scanf("%s", parsingTable[i][j]);
        }
    }

    printf("\nLL(1) Parsing Table:\n");
    printf("------------------------------\n");
    printf("Non-Terminals\tTerminals\tAction\n");
    printf("------------------------------\n");
    for (int i = 0; i < numNonTerminals; i++) {
        for (int j = 0; j < numTerminals; j++) {
            printf("%s\t\t%s\t\t%s\n", nonTerminals[i], terminals[j], parsingTable[i][j]);
        }
    }
    printf("------------------------------\n");

    return 0;
}