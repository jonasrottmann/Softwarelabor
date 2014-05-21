//
//  aufgabe_2_pointer.c
//  aufgabe_2_pointer
//
//  Created by Jonas Rottmann on 02.04.14.
//
//

#include <stdio.h>
#include <string.h>

// Falls notwendig erweitern Sie die Liste der includes

/**
 @brief Aufgabe2a: Scannen durch einen String
 @param [in] char* input
 @return char*
 
 Input ist ein String der aus alphanumerischen Zeichen besteht die
 durch :: getrennt sein koennen. Als Beispiele betrachte man
 
 <p>
    <ul>
        <li> "Ha::ll::o"
        <li> "47::11"
    </ul>
 
    Ihre Aufgabe ist es eine Funktion zu schreiben die den
    laengsten suffix (Endung) liefert der kein :: enthaelt.
    Laengste Endungen fuer unsere Beispiele:
    <ul>
        <li> "o"
        <li> "11"
    </ul>
 <p>
 
 Input ist der String (char pointer), das Ergebnis soll als
 return Wert geliefert werden, welcher ein Zeiger auf den
 Anfang der laengsten Endung ohne :: ist.
 */
char* extract(char* input) {
    if( strlen(input) > 0) {                                   // Prüfe ob input nicht leer ist (wenn leer, dann if(0) -> false)
        unsigned short int i = strlen(input) - 1;           // i ist der Index des letzten Zeichen
        while(i > 0) {                                      // solange i größer 0 (solange i nicht das erste Zeichen ist)
            if(input[i] == ':' && input[i - 1] == ':') {    // Wenn zwei ':' auf einander folgen
                return input + i + 1;                       // + 1, weil i der Index des hinteren ':' ist
            }
            i--;
        }
    }
    return input;
}

/**
 @brief Aufgabe2b: Variation von 2a
 @param [in] char* input
 @param [out] char** output
 
 Das Ergebnis soll hier nicht als return Wert geliefert werden.
 Anstatt wird ein pointer auf einen pointer verwendet.
 Wieso reicht ein pointer nicht aus?
*/

void extract2(char* input, char** output) {
    *output = extract(input);
}

/**
 @brief Aufgabe2c: Weitere Variation von Scannen
 @param [in] char* input
 @return int
 
 Input ist ein String der aus einer Liste von alphanumerischen Woertern
 die durch Leerzeichen (white-space) getrennt sind.
 Ihre Aufgabe ist es eine Funktion zu schreiben, die die Anzahl der
 Woerter zaehlt.
 <p>
 Beispiel:  "Ha ll o 5"
 <p>
 Soll liefern 4
 */

int count(char* input) {
    unsigned short int i = 0;
    unsigned short int countWords = 0;
    
    while(i < strlen(input)) {
        if(input[i] != ' ') {           //Anfang eines Wortes finden
            while(input[i] != ' ' && input[i] != '\0') {
                i++;                    //Zum ersten Zeichen nach Ende des Wortes springen
            }
            countWords++;               //Wort zählen
        }
        i++;
    }
    return countWords;
}


/**
 @brief Aufgabe2d: Aufsammeln von Woertern. Erweiterung von Aufgabe2c.
 @param [in] char* line
 @param [in] int maxwords
 @param [out] char* words[]
 @return int Anzahl aufgesammelter Woerter
 
 Gegeben (als Input) ist ein String der aus einer Liste von alphanumerischen
 Woertern die durch Leerzeichen (white-space) getrennt sind.
 Ihre Aufgabe ist es die Woerter in einem Array von Strings aufzusammeln.
 Das Array von Strings words wird pre-allokiert mit fester Groesse (maxwords).
 Die Anzahl der aufgesammelten Woerter wird als return Wert zurueck
 geliefert.
 
 */

int breakIntoWords(char *line, int maxwords, char *words[]) {
    char *p = line; // Pointer aufs erste Zeichen der Zeile
    unsigned short int countwords = 0;
    
    while(countwords < maxwords) {
        while (*p == ' ' && *p != '\0') { // Gehe mit p weiter bis zum ersten "Nicht-Leerzeichen"
            p++;
        }
        if (*p == '\0') { // Ende der Zeile erreicht
            return countwords;
        }
                            // Jetzt: Erstes "Nicht-Leerzeichen", was nicht das Ende der Zeile ist
        char *q = p;
        while(*q != ' ' && *q != '\0') { //Suche Ende des Wortes
            q++;
        }
        if(*q == '\0') { // Ende der Zeile schon erreicht => Letztes Wort der Zeile speichern
            return countwords;
        }
        else {
            *q = '\0'; // Setze Nullzeichen am Ende des Wortes
            p = q; // Setze p auf des Nullzeichen
            p++;
        }
        words[countwords] = p; //Füge Wort dem Array hinzu
        countwords++;
    }
    return countwords;
}


int main() {
    // Ihre Testroutinen
    char* test_a = "Ha::ll::oo";
    char* test_c = " Das  funktioniert  ja wunderbar !";
    char** output = &test_a;
    
    //2a
    printf("Aufgabe 2 a : '%s'\n", extract(test_a));
    
    //2b
    extract2(test_a, output);
    printf("Aufgabe 2 b : '%s'\n", *output);
    
    //2c
    printf("Aufgabe 2 c : '%s' - Anzahl der Wörter %i \n", test_c, count(test_c));
    
    //2d
    printf("Aufgabe 2 d : \n");
    //Beispieltest fuer Aufgabe2d
     char line[] = " hello this is a test ";
     int i;
     int nwords;
     char* words[10];
     
     nwords = breakIntoWords(line, 10, words);
     for(i = 0; i < nwords; i++)
         printf("%s\n", words[i]);
     /*soll liefern
     
     this
     is
     a
     test
     
     */
    printf("Anzahl Wörter: %i\n", nwords);
    
    return 0;
}
