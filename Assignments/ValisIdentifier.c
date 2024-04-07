/* Write a C program to test whether a given identifier is valid or not. */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValidIdentifier(const char* identifier) {
    if (strlen(identifier) == 0) {
        return false;
    }

    if (!(identifier[0] == '_' || (identifier[0] >= 'a' && identifier[0] <= 'z') || (identifier[0] >= 'A' && identifier[0] <= 'Z'))) {
        return false;
    }

    for (int i = 1; i < strlen(identifier); i++) {
        if (!(identifier[i] == '_' || (identifier[i] >= 'a' && identifier[i] <= 'z') || (identifier[i] >= 'A' && identifier[i] <= 'Z') || (identifier[i] >= '0' && identifier[i] <= '9'))) {
            return false;
        }
    }

    return true;
}

int main() {
    char identifier[100];

    printf("Enter an identifier: ");
    scanf("%s", identifier);

    if (isValidIdentifier(identifier)) {
        printf("Valid identifier\n");
    } else {
        printf("Invalid identifier\n");
    }

    return 0;
}
