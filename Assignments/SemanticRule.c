#include <stdio.h>

int calculateExpression(char* expression) {
    int result = 0;
    int num = 0;
    char op = '+';

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            num = num * 10 + (expression[i] - '0');
        }

        if (expression[i] == '+' || expression[i] == '*' || expression[i] == '\0') {
            if (op == '+') {
                result += num;
            } else if (op == '*') {
                result *= num;
            }

            num = 0;
            op = expression[i];
        }
    }

    return result;
}

int main() {
    char expression[100];

    printf("Enter the expression: ");
    scanf("%s", expression);

    int result = calculateExpression(expression);

    printf("Result: %d\n", result);

    return 0;
}