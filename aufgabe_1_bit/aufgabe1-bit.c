/**
 * @file   aufgabe1-bit.c
 * @brief  Aufgabe1 - Bit Manipulationen 
 */

#include <stdio.h>
// Falls notwendig erweitern Sie die Liste der includes

/**
   @brief Aufgabe1a: Vertauschen von Bytes
   @param [in] short int i
   @return short int

Schreiben Sie eine Funktion die das Low Byte (Bits 0-7) und 
das High Byte (Bits 8-15) vertauscht.
Z.B. aus der Zahl 0x4020 wird die Zahl 0x2040.
*/

short int switchLowHighByte(short int input) {
    return (input << 8) | ((unsigned short int) input >> 8);
}

typedef enum {
  Stop = 0,
  Start = 1,
  Finish = 5,
  Fail = 255
} Status;


typedef enum {
  One = 1,
  Fifteen = 15,
  Last = 255
} Numbers;

/**
   @brief Aufgabe1b: Serialisierung von Datenstrukturen
   @param [in] Status s
   @param [in] Numbers n
   @param [out] short int* data  

Gegeben sind zwei enums. Ihre Aufgabe ist es jeweils Werte der 
beiden enums in ein Datenpacket der Groesse 16Bit zu packen (serialisieren).
Werte des enums Status sollen dabei in das Low Byte und Werte
des enums Numbers sollen in das High Byte gepackt werden.
*/

void serialize(Status s, Numbers n, short int* data) {
    *data = (short int) (((unsigned short int) n << 8) | s);
}

/**
   @brief Aufgabe1c: Deserialisierung von Datenstrukturen
   @param [in] short int data
   @param [out] Status* s
   @param [out] Numbers* n

Schreiben Sie eine Funktion die Werte der enums Status und Number
aus einem 16Bit Wert entpackt (deserialisiert).
Wir nehmen an, dass die enum Werte mittels der serialize Funktion
verpackt wurden.
*/

void deserialize(short int data, Status* s, Numbers* n) {
    *s = data & 0x00FF;
    *n = ((unsigned short int) data >> 8);
}


//////// T E S T S ////////

enum TestEnum {
  OK = 0,
  FAIL = !OK
};

typedef enum TestEnum Test;

Test testLowHigh(short int i) {
  Test t;
  if(i == switchLowHighByte(switchLowHighByte(i))) 
    t = OK;
  else
    t = FAIL;

  return t;
}

Test testSD(Status s, Numbers n) {
    Test t;
    short int data;
    Status s2;
    Numbers n2;
    
    // Test execution
    serialize(s, n, &data);
    deserialize(data, &s2, &n2);
    if(s2 == s && n2 == n) {
        t = OK;
    }
    else {
        t = FAIL; }
    return t;
}



int main() {
    // Ihre Testroutinen
    short int zahl = 0x2040;
    
    printf("Aufgabe 1 a:\n");
    printf("%x \n", zahl);
    printf("%x \n", switchLowHighByte(zahl));
    
    printf("Aufgabe 1 b :\n");
    printf("%u \n\n", testSD(Finish, One));
    
    return 0;
}
