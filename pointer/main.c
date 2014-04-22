#include <stdio.h>

//Call-by-Value (Kopie)
void mache_was1(long i)
{
    i = 1;
}

//Call-by-Reference
void mache_was2(long * i) // long * i - Verweis auf long-Variable
{
    *i = 1; //Dereferenzierung
}

int main(int argc, const char * argv[])
{
    long i = 2;
    long j = 5;
    
    //Call-by-Value
    mache_was1(i);
    printf("%ld\n", i);

    //Call-by-Reference
    mache_was2(&i);
    printf("%ld\n", i);
    
    //Zeiger Operatoren +, -, ++, --
    long *p = &j;
    p= p+1;
    *p = 0;
    printf("%ld\n", i);
    
    
    //09. April
    int *p;
    int **q;
    int x;
    int y;
    
    
    q = &p;
    p = &x;
    **q = 1; //Dereferenzierung
    p = &y;
    **q = 2;
    
    return 0;
}

