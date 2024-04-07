/*Design a lexical analyzer for given language and the lexical analyzer should ignore redundant spaces, tabs and new
lines. It should also ignore comments. Although the syntax specification states that identifiers can be arbitrarily long,
you may restrict the length to some reasonable value. Simulate the same in C language.*/
#include <stdio.h>
#include <ctype.h>

#define MAX_IDENTIFIER_LENGTH 50

int main() {
    FILE *file;
    char ch;
    char identifier[MAX_IDENTIFIER_LENGTH];
    int identifierLength = 0;
    int inComment = 0;

    file = fopen("/Users/devadityaroy/Documents/Programming Languages/C/Compiler Design Lab/Lexical Analyser/Comments.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        if (inComment) {
            if (ch == '*' && (ch = fgetc(file)) == '/') {
                inComment = 0;
            }
        } else {
            if (isspace(ch)) {
                continue;
            } else if (ch == '/') {
                if ((ch = fgetc(file)) == '*') {
                    inComment = 1;
                } else {
                    fseek(file, -1, SEEK_CUR);
                    printf("Operator: /\n");
                }
            } else if (isalpha(ch)) {
                identifierLength = 0;
                identifier[identifierLength++] = ch;
                while ((ch = fgetc(file)) != EOF && isalnum(ch) && identifierLength < MAX_IDENTIFIER_LENGTH) {
                    identifier[identifierLength++] = ch;
                }
                identifier[identifierLength] = '\0';
                fseek(file, -1, SEEK_CUR);
                printf("Identifier: %s\n", identifier);
            } else {
                printf("Invalid character: %c\n", ch);
            }
        }
    }

    fclose(file);
    return 0;
}
