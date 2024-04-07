%{
#include <stdio.h>
%}

%%

[ \t\n]           ; // Ignore whitespace

[0-9]+            { printf("Integer: %s\n", yytext); }

[a-zA-Z][a-zA-Z0-9]*   { printf("Identifier: %s\n", yytext); }

[-+*/]            { printf("Operator: %s\n", yytext); }

.                 { printf("Invalid character: %s\n", yytext); }

%%

int main() {
    yylex();
    return 0;
}

