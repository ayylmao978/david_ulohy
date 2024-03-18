#include <stdio.h>
#include <ctype.h>
#include <string.h>

// funkcne prototypy
void zmensi(char s[], int dlzka);
void zvacsi(char s[], int dlzka);
void exchange(char s[], int dlzka);



int main()
{
    char retazec[31];
    printf("Zadavajte retazce ('l' - zmensi, 'u' - zvacsi, 'x' - zamen) : \n");
    while (scanf("%s", retazec)) // vracia pocet precitanych znakov - v tomto pripade 1 - co znamena true
    {   
        int dlzka = strlen(retazec);
        switch (retazec[dlzka - 1])
        {
            case 'l':
            case 'L':
                zmensi(retazec, dlzka);
                break;
            
            case 'u':
            case 'U':
                zvacsi(retazec, dlzka);
                break;

            case 'x':
            case 'X':
                exchange(retazec, dlzka);
                break;
            
            default:
                break;
            
        }
        printf("%s\n", retazec);

    }
    return 0;
}



void zmensi(char s[], int dlzka)
{
    for (int i = 0; i < dlzka; i++)
    {
        s[i] = tolower(s[i]);
    }

}


void zvacsi(char s[], int dlzka)
{
    for (int i = 0; i < dlzka; i++)
    {
        s[i] = toupper(s[i]);
    }
}


void exchange(char s[], int dlzka)
{   
    for (int i = 0; i < dlzka; i++)
    {  
        if (islower(s[i]))
            s[i] = toupper(s[i]);
        else
            s[i] = tolower(s[i]);
    }
}