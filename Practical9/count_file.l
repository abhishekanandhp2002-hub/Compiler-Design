%{
#include <stdio.h>

int lines=0, words=0;
int s_letters=0, c_letters=0;
int num=0, spl_char=0, total=0;

FILE *yyin;
%}

%%

\n          { lines++; words++; }
[ \t]       { words++; }
[A-Z]       { c_letters++; }
[a-z]       { s_letters++; }
[0-9]       { num++; }
.           { spl_char++; }

%%

int main()
{
    yyin = fopen("practical9.txt","r");

    if(!yyin)
    {
        printf("File not found\n");
        return 1;
    }

    yylex();

    total = s_letters + c_letters + num + spl_char;

    printf("\nThis File contains ...\n");
    printf("%d lines\n", lines);
    printf("%d words\n", words);
    printf("%d small letters\n", s_letters);
    printf("%d capital letters\n", c_letters);
    printf("%d digits\n", num);
    printf("%d special characters\n", spl_char);
    printf("Total %d characters\n", total);

    return 0;
}

int yywrap()
{
    return 1;
}
