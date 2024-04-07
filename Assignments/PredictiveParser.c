//E -> E + T | E - T | T
//T -> T * F | T / F | F
//F -> ( E ) | number

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char lookahead;
char *input;

void error() {
    printf("Error: Invalid input\n");
    exit(1);
}

void match(char expected) {
    if (lookahead == expected) {
        lookahead = *(++input);
    } else {
        error();
    }
}

void factor();
void term();
void expression();

void factor() {
    if (isdigit(lookahead)) {
        printf("Number: %c\n", lookahead);
        match(lookahead);
    } else if (lookahead == '(') {
        match('(');
        expression();
        match(')');
    } else {
        error();
    }
}

void term() {
    factor();
    while (lookahead == '*' || lookahead == '/') {
        printf("Operator: %c\n", lookahead);
        match(lookahead);
        factor();
    }
}

void expression() {
    term();
    while (lookahead == '+' || lookahead == '-') {
        printf("Operator: %c\n", lookahead);
        match(lookahead);
        term();
    }
}

int main() {
    printf("Enter an arithmetic expression: ");
    input = malloc(100 * sizeof(char));
    fgets(input, 100, stdin);

    lookahead = *input;

    expression();

    if (lookahead == '\n' || lookahead == '\0') {
        printf("Parsing successful.\n");
    } else {
        error();
    }

    free(input);
    return 0;
}
