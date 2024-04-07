/* Write a C program to simulate lexical analyzer for validating operators.*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isOperator(char ch) {
    char operators[] = "+-*/%=";
    for (int i = 0; i < strlen(operators); i++) {
        if (ch == operators[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    char input;
    printf("Enter an operator: ");
    scanf("%c", &input);

    if (isOperator(input)) {
        printf("Valid operator\n");
    } else {
        printf("Invalid operator\n");
    }

    return 0;
}
