#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strins(char s1[], char s2[], int i);

int main()
{
    char s1[51] = "Toto je string cislo jeden";
    char s2[51] = "Druhy string je tento";

    strins(s1, s2, 6);

    printf("%s", s1);
    return 0;
}


void strins(char s1[], char s2[], int i)
{
    char *p_s1 = s1;
    p_s1 += i;
    
    *p_s1 = '\0';  // tu zacne vkladat strcat vdaka null znaku

    strcat(p_s1, s2);
}