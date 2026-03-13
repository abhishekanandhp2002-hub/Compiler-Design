#include <stdio.h>
#include <string.h>

int main()
{
    char stack[20], ip[20], ter[10];
    char opt[10][10];
    int i, j, k, n, top = 0, row, col, len;

    printf("Enter the number of terminals: ");
    scanf("%d", &n);

    printf("Enter the terminals: ");
    scanf("%s", ter);

    printf("\nEnter the operator precedence table:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("Enter relation for %c %c: ", ter[i], ter[j]);
            scanf(" %c", &opt[i][j]);
        }
    }

    printf("\nOperator Precedence Table\n");

    printf("\t");
    for(i = 0; i < n; i++)
        printf("%c\t", ter[i]);

    printf("\n");

    for(i = 0; i < n; i++)
    {
        printf("%c\t", ter[i]);
        for(j = 0; j < n; j++)
            printf("%c\t", opt[i][j]);
        printf("\n");
    }

    stack[top] = '$';
    stack[top+1] = '\0';

    printf("\nEnter input string (end with $): ");
    scanf("%s", ip);

    printf("\nSTACK\tINPUT\tACTION\n");

    i = 0;
    len = strlen(ip);

    while(i < len)
    {
        for(k = 0; k < n; k++)
        {
            if(stack[top] == ter[k])
                row = k;
            if(ip[i] == ter[k])
                col = k;
        }

        if(stack[top] == '$' && ip[i] == '$')
        {
            printf("%s\t%s\tACCEPT\n", stack, ip);
            break;
        }
        else if(opt[row][col] == '<' || opt[row][col] == '=')
        {
            stack[++top] = ip[i];
            stack[top+1] = '\0';

            printf("%s\t%s\tSHIFT\n", stack, ip);

            i++;
        }
        else if(opt[row][col] == '>')
        {
            printf("%s\t%s\tREDUCE\n", stack, ip);

            top--;
            stack[top+1] = '\0';
        }
        else
        {
            printf("String not accepted\n");
            break;
        }
    }

    return 0;
}
