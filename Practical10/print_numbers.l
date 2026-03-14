%{
#include <stdio.h>
int num = 0;
FILE *yyin;
%}

%%

[0-9]+   { printf("%s\n", yytext); num++; }
.|\n     ;

%%

int main()
{
    yyin = fopen("practical10.txt","r");

    if(!yyin)
    {
        printf("File not found\n");
        return 1;
    }

    yylex();

    printf("\nTotal numbers: %d\n", num);
    return 0;
}

int yywrap()
{
    return 1;
}
