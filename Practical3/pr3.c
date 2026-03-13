#include <stdio.h>
#include <string.h>

int main()
{
    int i, at = 0, sp = 0, c = 0, n = 0, s = 0, spl = 0;
    char username[20], password[20];

    printf("Enter user name: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for(i = 0; i < strlen(username); i++)
    {
        if(username[i] == '@')
            at++;
        if(username[i] == '.')
            sp++;
    }

    for(i = 0; i < strlen(password); i++)
    {
        if(password[i] >= 'A' && password[i] <= 'Z')
            c++;

        if(password[i] >= '0' && password[i] <= '9')
            n++;

        if(password[i] >= 'a' && password[i] <= 'z')
            s++;

        else
            spl++;
    }

    if(at != 1)
        printf("\nInvalid user name");
    else
        printf("\nValid user name");

    if(c < 1 || n < 1 || s < 1 || spl < 1 || strlen(password) < 8)
        printf("\nInvalid password");
    else
        printf("\nValid password");

    return 0;
}
