#include <stdio.h>
#include <string.h>


int main()
{
    char nazov[20 + 1];
    char typ[3 + 1];
    char znak;

    printf("Zadaj nazov suboru :\n");
    scanf("%s", nazov);

    printf("Zadaj typ suboru (max 3 znaky!) :\n");
    scanf("%3s", typ);

    // zbavovanie sa znakov naviac
    while (getchar() != '\n')
        ;

    printf("Zadaj znak :\n");
    znak = getchar();

    strcat(nazov, "."); // subor.
    strcat(nazov, typ); // subor.txt

    FILE *fr;
    if ((fr = fopen(nazov, "r")) == NULL)
    {
        printf("Nastala chyba pri otvarani suboru\n");
        return -1;
    }


    char veta[501];

    putchar(znak);

    while (fgets(veta, 500, fr) != NULL)  // opat je kontrola na null zbytocna...
    {
        if (strchr(veta, znak) != NULL)
        {
            printf("%s", veta);
        }
    }



    if (fclose(fr) == EOF)
    {
        printf("Nastala chyba pri zatvarani suboru\n");
        return -1;
    }


    return 0;
}