#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int performOperation(int operand1, int operand2, char operator) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        default:
            printf("Invalid operator\n");
            exit(EXIT_FAILURE);
    }
}

int evaluateExpression(char* expression) {
    int i, operand1, operand2, result;
    char operator;

    int operandStack[100];
    int top = -1;

    char operatorStack[100];
    int operatorTop = -1;

    for (i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == ' ') {
            continue;
        }
        else if (!isOperator(expression[i])) {
            operandStack[++top] = expression[i] - '0';
        }
        else {
            if (operatorTop == -1 || expression[i] == '(' || expression[i] == '*' || expression[i] == '/') {
                operatorStack[++operatorTop] = expression[i];
            }
            else {
                operand2 = operandStack[top--];
                operand1 = operandStack[top--];
                operator = operatorStack[operatorTop--];
                result = performOperation(operand1, operand2, operator);
                operandStack[++top] = result;
                i--; 
            }
        }
    }

    while (operatorTop != -1) {
        operand2 = operandStack[top--];
        operand1 = operandStack[top--];
        operator = operatorStack[operatorTop--];
        result = performOperation(operand1, operand2, operator);
        operandStack[++top] = result;
    }

    return operandStack[top];
}

int main() {
    char expression[100];

    printf("Enter an expression: ");
    fgets(expression, sizeof(expression), stdin);

    int result = evaluateExpression(expression);
    printf("Result: %d\n", result);

    return 0;
}