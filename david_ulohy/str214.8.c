#include <stdio.h>
#include <string.h>


int main()
{
    char nazov[20 + 1];
    char typ[3 + 1];

    printf("Zadaj nazov suboru :\n");
    scanf("%s", nazov);

    printf("Zadaj typ suboru (max 3 znaky!) :\n");
    scanf("%3s", typ);

    strcat(nazov, "."); // subor.
    strcat(nazov, typ); // subor.txt


    char veta[501];

    FILE *fr;
    if ((fr = fopen(nazov, "r")) == NULL)
    {
        printf("Nastala chyba pri otvarani suboru\n");
        return -1;
    }

    while (fgets(veta, 500, fr) != NULL)  // opat je kontrola na null zbytocna...
    {
        printf("%s", veta);
    }


    if (fclose(fr) == EOF)
    {
        printf("Nastala chyba pri zatvarani suboru\n");
        return -1;
    }


    return 0;
}