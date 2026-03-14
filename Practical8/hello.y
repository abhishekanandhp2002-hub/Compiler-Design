%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
int yyerror(const char *s);
%}

%token HI BYE

%%

program:
    hi bye
;

hi:
    HI { printf("Hello World\n"); }
;

bye:
    BYE { printf("Bye World\n"); exit(0); }
;

%%

int yyerror(const char *s)
{
    printf("Error: %s\n",s);
    return 0;
}
