%{
#include <stdio.h>
FILE *yyin;
%}

%%

\<[^>]*\>   { printf("%s\n", yytext); }
.|\n        ;

%%

int main()
{
    yyin = fopen("practical10b.txt","r");

    if(!yyin)
    {
        printf("File not found\n");
        return 1;
    }

    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
