#include <stdio.h>
#include <stdlib.h>


int set(char vstup, char *vyystup)
{
    if (vyystup == NULL)
        return -1;
    if ((vstup >= 'A' && vstup <= 'Z')) {
        *vyystup = (vstup + 32);
        return 1;
    }
    else if ((vstup >= 'a' && vstup <= 'z')) {
        *vyystup = (vstup - 32);
        return 1;
    }
    // neni potreba else statementu, konci mi funkcia. . .
    *vyystup = vstup;
    return 0;

}


int main()
{

    char c;
    char vystupny;
    printf("Zadavajte znaky : \n");
    while ((c = getchar()) != '\n') {
        getchar();

        printf("hodnota funkcie bola : %d, vstup bol: %c", set(c, &vystupny), c);
        printf(", vystup je : %c\n", vystupny);
    }
    return 0;
}
