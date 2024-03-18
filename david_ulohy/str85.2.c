#include <stdio.h>

int main()
{
    FILE *fr, *fw;
    fr = fopen("texty\\PISMENA.TXT", "r");
    fw = fopen("texty\\VELKA.TXT", "w");

    int c;
    while ((c = getc(fr)) != EOF) {
        printf("%c", c);
        if ((('A' <= c) && (c <= 'Z')) || (c == ' ') || (c == '\n')) {
            putc(c, fw); // Zapisanie velkeho pismena do suboru VELKA.TXT
        }
        else {
            c -= 32;
            putc(c, fw); // Zapisanie velkeho pismena (s posunom) do suboru VELKA.TXT
        }
    }

    fclose(fr); fclose(fw);

    return 0;
}