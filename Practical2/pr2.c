#include <stdio.h>

int main()
{
    char str[50];
    int vowels = 0, digit = 0, special = 0, consonant = 0;

    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||
            str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
        {
            vowels++;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            digit++;
        }
        else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            consonant++;
        }
        else
        {
            special++;
        }
    }

    printf("Vowels: %d\n", vowels);
    printf("Digits: %d\n", digit);
    printf("Special characters: %d\n", special);

    return 0;
}
