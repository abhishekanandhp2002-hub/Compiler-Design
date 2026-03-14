%{
#include <stdio.h>

int vow_count = 0;
int const_count = 0;

FILE *yyin;
%}

%%

[aeiouAEIOU]                { vow_count++; }
[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z]   { const_count++; }
.                           { }

%%

int main()
{
    yyin = fopen("practical8.txt","r");

    if(!yyin)
    {
        printf("File not found!\n");
        return 1;
    }

    yylex();

    printf("Number of vowels: %d\n", vow_count);
    printf("Number of consonants: %d\n", const_count);

    return 0;
}

int yywrap()
{
    return 1;
}
