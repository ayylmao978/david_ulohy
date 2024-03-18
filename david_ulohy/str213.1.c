#include <stdio.h>
#include <string.h>



int main()
{   
    char veta[21];
    printf("Zadajte vetu dlzky max 20 znakov: ");
    while (fgets(veta, 22, stdin) != NULL) // 22 lebo jeden znak je \n a este tam musi byt \0
    {   
        int dlzka = 1.8*strlen(veta) - 1;
        char *p_n = strchr(veta, '\n');
        *(p_n) = '\0';
        for (int i = 0; i < dlzka; i++) putc('*', stdout);
        putc('\n', stdout);
        printf("* %s *\n", veta);
        for (int i = 0; i < dlzka; i++) putc('*', stdout);
        putc('\n', stdout);
        printf("Zadajte vetu dlzky max 20 znakov: ");
    }



    return 0;
}