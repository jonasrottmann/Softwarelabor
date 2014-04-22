//
//  main.c
//  vorlesung_array_2dim
//
//  Created by Jonas Rottmann on 09.04.14.
//
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
    char* p[] = { NULL, NULL, NULL, NULL };
    char *s1 = "ABC";
    char *s2 = "123";
    
    char *q[2];
    q[0] = s1;
    q[1] = s2;
    
    //2 dimensionales Feld im Speicher immer sequenziell in einer bestimmten Reihenfolge
    char r[2][4] ={"ABC", "123"}; // gleich wie {{'A', 'B', 'C', '\0'}, {'1','2','3','\0'}}
    printf("%s, %s \n", r[0], r[1]);
    
    char *t = (char *) r; //r ist die anfangsspeicherbereichadresse
    printf("%s\n", (t + 4));
    
    return 0;
}

