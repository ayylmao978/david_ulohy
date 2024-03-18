#include <string.h>
#include <stdio.h>


int main()
{
    printf("Zadajte riadok :\n");
    char retazec[21]; // 20 znakov + '\0'
    while (fgets(retazec, 22, stdin) != NULL)
    {       
             
        int znak;

        printf("Zadajte znak, lebo ENTER pre ukoncenie :\n");

        if ((znak = getchar()) == '\n')
            return 0;

        //zbavenie sa znakov z terminalu - '\n' alebo ine znaky,  ak uzivatel kkt zadal slovo a ne jeden znak
        while (getchar() != '\n')
            ;

        // zbavit sa \n z retazca, kedze fgets uklada do retazca aj \n.    20 znakov + \n + \0
        int dlzka = strlen(retazec);
        retazec[dlzka-1] = '\0';

        char *p_c;
        while ((p_c = strchr(retazec, znak)) != NULL)  // ziadna kontrola na null tu byt nemusi, kedze null znamena 0 znamena false
        {
            *p_c = '*';
        }
        printf("%s\n", retazec);
        printf("Zadajte novy riadok :\n");
    }

    return 0;
}
