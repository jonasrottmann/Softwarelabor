//
//  String.cpp
//  softwarelabor_c
//
//  Created by Jonas Rottmann on 21.05.14.
//
//

#include "String.h"
#include <iostream>
using namespace std;

class String
{

private:
    int size;
    char* str;

    template <class T>
    void copy(T &source, char* dest, int count, int offset)
    {
        int i;
        for (i = 0; i < count; i++)
        {
            dest[i + offset] = source[i];
        }
        dest[count] = '\0';
    }
    
public:
    //Konstruktor Standard
    String()
    {
        size = 0;
        str = new char[1];
        str[0] = '\0';
    }
    
    //Konstruktor Character
    String(char c)
    {
        size = 1;
        str = new char[2];
        str[0] = c;
        str[size] = '\0';
    }
    
    //Konstruktor C-String
    String(char* c)
    {
        int counter = 0;
        while (c[counter] != '\0')
        {
            counter++;
        }
        str = new char[counter + 1];
        size = counter;
        copy(c, str, size, 0);
    }
    
    //Kopierkonstruktor
    String(String &s)
    {
        size = s.getSize();
        str = new char[size + 1];
        copy(s, str, size, 0);
    }
    
    //Getter
    int getSize()
    {
        return size;
    }
    
    //Dekonstruktor
    ~String()
    {
        delete[] str;
    }
    
    //Overload Arrayzugriff
    char& operator [](int index)
    {
        return str[index];
    }
    
    //Overload +=
    void operator +=(String &s)
    {
        int newsize = size + s.getSize();
        char* newstr = new char[newsize + 1];
        
        copy(str, newstr, size, 0);
        copy(s, newstr, newsize, size);
        
        size = newsize;
        delete[] str;
        str = newstr;
    }
    
    //Overload =
    void operator =(String &s)
    {
        char* newstr = new char[s.getSize() + 1];
        delete[] str;
        str = newstr;
        size = s.getSize();
        copy(s, str, size, 0);
    }
    
    // make friend, so we can access private members
    friend ostream& operator <<(ostream &out, String &s);
};



ostream& operator<< (ostream &out, String &s)
{
    for(int i = 0; i < s.size; i++)
    {
        out << s.str[i];
    }
    return out;
}

int main(int argc, const char * argv[])
{
    //Todo: Tests
    String s2("Test");
    String s3(s2);
    
    s3 = s2;
    
    cout << s3 << endl;
};
