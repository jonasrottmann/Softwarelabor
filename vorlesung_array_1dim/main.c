#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    //Long Strings
    long zahlen1[10]; //noch nicht initialisiert
    long zahlen2[10] = {7, -1}; //nur die ersten beiden Werte sind initialisiert
    long zahlen3[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; //
    long zahlen4[] = {1, 2, 3, 4}; //Kurzform
    
    zahlen4[1] = 0;
    printf("%ld\n%ld\n", zahlen4[0], zahlen4[1]);
    
    
    //"C-Strings" - Null terminierte character Felder
    char name1[10] = {'P', 'a', 'p', 'e', '\0'};
    char name2[10] = {"Pape"};
    printf("%s\n%s\n", name1, name2);
    
    //strlen in string.h, Anzahl der Zeichen bis zum ersten Vorkommen des Nullzeichen '\0'.
    printf("%lu\n", strlen(name1));
    
    //Zugriff über Pointer (NUR in eindimensionalen Feldern!)
    char *p = name1;
    *p = 'p';
    p++;
    *p = 'A';
    *(p+1) = 'P';
    p[2] = 'E';
    printf("%s\n", name1);
    
    return 0;
}

