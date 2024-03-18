#include <string.h>
#include <stdlib.h>
#include <stdio.h>


int main()
{
    char pole_x[20];
    strcpy(pole_x, "Toto je priklad");
    char *p_char;
    p_char = (char *) malloc(20*sizeof(char));
    strcpy(p_char, pole_x);
    printf("%s", p_char);


    return 0;
}