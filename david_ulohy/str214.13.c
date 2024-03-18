#include <stdio.h>
#include <string.h>


void strdel(char s[], int i, int n);

int main()
{
    char retazec1[] = "Toto";

    strdel(retazec1, 1, 4);

    printf("%s", retazec1);

    return 0;
}



void strdel(char s[], int i, int n)
{
    char *p_s = s;
    
    // aby sme nemazali data za stringom alebo znak '\0'
    if (((strlen(s)-1) - i - n) >= 0)
    {
        printf("Chyba\n");
        return;
    }
    // posunutie na spravnu poziciu
    p_s += i;

    // mazanie znakov
    for (int k = 0; k < n; k++)
    {
        *p_s++ = ' '; // == *p_s = ' ';  p_s++;
    }
}