#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int counter = 0;

bool isDelimiter(char ch)
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
        ch == ',' || ch == ';' || ch == '>' || ch == '<' || ch == '=' ||
        ch == '(' || ch == ')' || ch == '[' || ch == ']' ||
        ch == '{' || ch == '}' || ch == '\n')
        return true;

    return false;
}

bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
        ch == '>' || ch == '<' || ch == '=' || ch == ',' ||
        ch == ';' || ch == '(' || ch == ')' ||
        ch == '{' || ch == '}')
        return true;

    return false;
}

bool validIdentifier(char* str)
{
    if ((str[0] >= '0' && str[0] <= '9') || isDelimiter(str[0]))
        return false;

    return true;
}

bool isKeyword(char* str)
{
    if (!strcmp(str, "if") || !strcmp(str, "else") ||
        !strcmp(str, "while") || !strcmp(str, "do") ||
        !strcmp(str, "break") || !strcmp(str, "continue") ||
        !strcmp(str, "int") || !strcmp(str, "double") ||
        !strcmp(str, "float") || !strcmp(str, "return") ||
        !strcmp(str, "char") || !strcmp(str, "case") ||
        !strcmp(str, "sizeof") || !strcmp(str, "long") ||
        !strcmp(str, "short") || !strcmp(str, "typedef") ||
        !strcmp(str, "switch") || !strcmp(str, "unsigned") ||
        !strcmp(str, "void") || !strcmp(str, "static") ||
        !strcmp(str, "struct") || !strcmp(str, "goto"))
        return true;

    return false;
}

bool isInteger(char* str)
{
    int i, len = strlen(str);

    if (len == 0)
        return false;

    for (i = 0; i < len; i++)
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return false;
    }

    return true;
}

bool isRealNumber(char* str)
{
    int i, len = strlen(str);
    bool hasDecimal = false;

    if (len == 0)
        return false;

    for (i = 0; i < len; i++)
    {
        if ((str[i] >= '0' && str[i] <= '9'))
            continue;
        else if (str[i] == '.')
            hasDecimal = true;
        else
            return false;
    }

    return hasDecimal;
}

char* subString(char* str, int left, int right)
{
    int i;
    char* subStr = (char*)malloc(sizeof(char) * (right - left + 2));

    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];

    subStr[right - left + 1] = '\0';

    return subStr;
}

void tokencounter(char* str)
{
    int left = 0, right = 0;
    int len = strlen(str);

    while (right <= len && left <= right)
    {
        if (!isDelimiter(str[right]))
            right++;

        if (isDelimiter(str[right]) && left == right)
        {
            if (isOperator(str[right]))
                counter++;

            right++;
            left = right;
        }

        else if ((isDelimiter(str[right]) && left != right) || (right == len && left != right))
        {
            char* subStr = subString(str, left, right - 1);

            if (isKeyword(subStr))
                counter++;
            else if (isInteger(subStr))
                counter++;
            else if (isRealNumber(subStr))
                counter++;
            else if (validIdentifier(subStr))
                counter++;
            else
                counter++;

            left = right;
        }
    }
}

int main()
{
    char str[100];

    printf("Please enter your program\n");
    printf("After completing program press TAB\n");

    scanf("%[^\t]", str);

    tokencounter(str);

    printf("\nThe count of total number of tokens in your program is %d\n", counter);

    return 0;
}
