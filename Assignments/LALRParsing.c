#include <stdio.h>
int parsingTable[5][4] = {
    {1, -1, -1, -1},
    {-1, 2, -1, -1},
    {-1, -1, 3, 4},
    {5, -1, -1, -1},
    {-1, -1, 6, -1}
};

int main() {
    int stack[1000];
    int top = -1;
    char input[1000];
    int i = 0;
    stack[++top] = 0;
    printf("Enter the input string: ");
    scanf("%s", input);
    while (1) {
        int currentState = stack[top];
        char currentInput = input[i];
        int action = parsingTable[currentState][currentInput - 'a'];
        if (action == -1) {
            printf("Error: Invalid input\n");
            break;
        } else if (action == 0) {
            printf("Accepted\n");
            break;
        } else if (action > 0) {
            stack[++top] = action;
            printf("Shift %d\n", action);
            i++;
        } else {
            printf("Reduce by rule %d\n", -action);
        }
    }
    
    return 0;
}