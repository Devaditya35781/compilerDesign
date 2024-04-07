/* Write a C program to recognize strings under 'a', 'a*b+', 'abb'*/
#include <stdio.h>
#include <stdbool.h>

bool recognizeString(char* str) {
    int state = 0;
    int i = 0;

    while (str[i] != '\0') {
        switch (state) {
            case 0:
                if (str[i] == 'a')
                    state = 1;
                    else
                    return false;
                break;
            case 1:
                if (str[i] == 'a')
                    state = 1;
                else if (str[i] == 'b')
                    state = 2;
                else 
                    return false;
                break;
            case 2:
                if (str[i] == 'b')
                    state = 2;
                else 
                    return false;
                break;
        }
        i++;
    }

    return state == 2;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    if (recognizeString(str))
        printf("String recognized!\n");
    else 
        printf("String not recognized!\n");

    return 0;
}