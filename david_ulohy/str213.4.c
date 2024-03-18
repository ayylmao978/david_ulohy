#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define ERROR        printf("Moc velke slovo\n")


int main()
{
// radg - radg gdar
    printf("Zadavajte slova, z ktorych vznikne palindrom :\n");

    char slovo[41];
    while (scanf("%s", &slovo))
    {
        int dlzka_s = strlen(slovo);
        if (dlzka_s > 20)
            ERROR;
            return -1;
        
        int i;
        for (i = 0; i < dlzka_s; i++)
        {
            slovo[2*dlzka_s - i - 1] = slovo[i];
        }
        slovo[i + dlzka_s] = '\0';
        printf("%s\n", slovo);
    }

    return 0;
}