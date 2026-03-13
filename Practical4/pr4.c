#include<stdio.h>
#include<ctype.h>
#include<string.h>

void findfirst(char, int, int);
void follow(char);
void followfirst(char, int, int);

int count, n = 0, m = 0;
char calc_first[10][100];
char calc_follow[10][100];
char production[10][10];
char first[10];
char f[10];

int k;
char ck;
int e;

int main()
{
    int jm = 0, km = 0;
    int i;
    char c, ch;

    printf("How many productions? : ");
    scanf("%d", &count);

    printf("\nEnter productions (Example: E=TR)\n");

    for(i = 0; i < count; i++)
    {
        scanf("%s%c", production[i], &ch);
    }

    char done[10];
    int ptr = -1;

    for(k = 0; k < count; k++)
    {
        for(i = 0; i < 100; i++)
        {
            calc_first[k][i] = '!';
        }
    }

    int point1 = 0, point2;

    for(k = 0; k < count; k++)
    {
        c = production[k][0];
        point2 = 0;

        int xxx = 0;

        for(i = 0; i <= ptr; i++)
        {
            if(c == done[i])
                xxx = 1;
        }

        if(xxx == 1)
            continue;

        findfirst(c, 0, 0);

        ptr++;
        done[ptr] = c;

        printf("\nFIRST(%c) = { ", c);

        calc_first[point1][point2++] = c;

        for(i = jm; i < n; i++)
        {
            printf("%c ", first[i]);
            calc_first[point1][point2++] = first[i];
        }

        printf("}\n");

        jm = n;
        point1++;
    }

    printf("\n");

    char donee[10];
    ptr = -1;

    for(k = 0; k < count; k++)
    {
        for(i = 0; i < 100; i++)
        {
            calc_follow[k][i] = '!';
        }
    }

    point1 = 0;

    for(e = 0; e < count; e++)
    {
        ck = production[e][0];
        point2 = 0;

        int xxx = 0;

        for(i = 0; i <= ptr; i++)
        {
            if(ck == donee[i])
                xxx = 1;
        }

        if(xxx == 1)
            continue;

        follow(ck);

        ptr++;
        donee[ptr] = ck;

        printf("FOLLOW(%c) = { ", ck);

        calc_follow[point1][point2++] = ck;

        for(i = km; i < m; i++)
        {
            printf("%c ", f[i]);
            calc_follow[point1][point2++] = f[i];
        }

        printf("}\n");

        km = m;
        point1++;
    }

    return 0;
}

void follow(char c)
{
    int i, j;

    if(production[0][0] == c)
        f[m++] = '$';

    for(i = 0; i < count; i++)
    {
        for(j = 2; j < strlen(production[i]); j++)
        {
            if(production[i][j] == c)
            {
                if(production[i][j+1] != '\0')
                    followfirst(production[i][j+1], i, j+2);

                if(production[i][j+1] == '\0' && c != production[i][0])
                    follow(production[i][0]);
            }
        }
    }
}

void findfirst(char c, int q1, int q2)
{
    int j;

    if(!(isupper(c)))
    {
        first[n++] = c;
        return;
    }

    for(j = 0; j < count; j++)
    {
        if(production[j][0] == c)
        {
            if(production[j][2] == '#')
            {
                if(production[q1][q2] == '\0')
                    first[n++] = '#';
                else
                    findfirst(production[q1][q2], q1, q2+1);
            }
            else if(!isupper(production[j][2]))
                first[n++] = production[j][2];
            else
                findfirst(production[j][2], j, 3);
        }
    }
}

void followfirst(char c, int c1, int c2)
{
    int i, j;

    if(!(isupper(c)))
        f[m++] = c;
    else
    {
        for(i = 0; i < count; i++)
        {
            if(calc_first[i][0] == c)
                break;
        }

        j = 1;

        while(calc_first[i][j] != '!')
        {
            if(calc_first[i][j] != '#')
                f[m++] = calc_first[i][j];
            else
            {
                if(production[c1][c2] == '\0')
                    follow(production[c1][0]);
                else
                    followfirst(production[c1][c2], c1, c2+1);
            }

            j++;
        }
    }
}
