/* Write a C program to identify whether a given line is a comment or not. */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int isComment(const char *line) {
    if (strlen(line) >= 2 && line[0] == '/' && line[1] == '/') 
        return 1;
    if (strlen(line) >= 2 && line[0] == '/' && line[1] == '*') 
        return 2;
    if (strlen(line) >= 2 && line[0] == '*' && line[1] == '/') 
        return 3;
    if (strstr(line, "*/") != NULL) 
        return 4;
    return 0;
}

int main() {
    char line[100];

    printf("Enter a line: ");
    fgets(line, sizeof(line), stdin);

    int commentType = isComment(line);
    if (commentType == 1)
        printf("Single-line comment detected.\n");
    else if (commentType == 2) 
        printf("Start of multi-line comment detected.\n");
    else if (commentType == 3) 
        printf("End of multi-line comment detected.\n");
    else if (commentType == 4) 
        printf("Inside multi-line comment detected.\n");
    else 
        printf("Not a comment.\n");

    return 0;
}
