#include <stdio.h>
#include <string.h>

int main()
{
    char retazec[31];

    fgets(retazec, 32, stdin);

    int i;
    char *p_c = retazec;
    for (i = 0; i < strlen(retazec); i++)
    {
        if (strchr(p_c, ' ') == p_c++)
            putchar('\n');
        else
            putchar(retazec[i]);
    }

    return 0;
}   