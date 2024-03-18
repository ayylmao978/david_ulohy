#define EOLN     '\n'

#include <ctype.h>
#include <stdio.h>

int main()
{
    int c, pocet;
    printf("Zadavajte znaky ! :)\n");
    while ((c = getchar()) != EOLN) {
        getchar();
        if (!(isdigit(c)) && (isalpha(c))) {
            printf("--\n%c\n", toupper(c));
            pocet += 1;
        }
    }   
    printf("%d je pocet platnych znakov", pocet);
    return 0;
}