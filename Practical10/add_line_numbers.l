%{
#include <stdio.h>
int line_number = 1;
FILE *yyin;
%}

%%

.*\n   { printf("%d %s", line_number++, yytext); }

%%

int main()
{
    yyin = fopen("add.txt","r");

    if(yyin == NULL)
    {
        printf("File Not Found\n");
        return 1;
    }

    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
