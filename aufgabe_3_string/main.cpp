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

class String {
private:
    // 'String' is represented internally as a plain C-style string.
    int size;
    char* str;
public:
    String() {
        size = 0;
        str = new char[1];
        str[0] = '\0';
    }
    String(char c) {
        size = 1;
        str = new char[2];
        str[0] = c;
        str[size] = '\0';
    }
    
    String(char* c) {
        
        unsigned short int counter = 0;
        while (c[counter] != '\0') {
            counter++;
        }
        size = counter;
        
        str = new char[size + 1];
        
        unsigned short int i;
        for (i = 0; i < size; i++) {
            str[i] = c[i];
        }
        str[size] = '\0';
    }
    
    String(String &s) {
        size = s.getSize();
        str = new char[s.getSize() + 1];
        
        unsigned short int i;
        for (i = 0; i < s.getSize(); i++) {
            str[i] = s[i];
        }
        str[s.getSize()] = '\0';
    }
    
    int getSize() {
        return size;
    }
    
    
    ~String() {
        delete[] str;
    }
    
    char& operator [](int index) {
        return str[index];
    }
    
    void operator +=(String &s) {
        int newsize = size + s.getSize();
        
        char* newstr = new char[newsize + 1];
        
        unsigned short int i;
        for (i=0; i < size; i++) {
            newstr[i] = str[i];
        }
        for (i=0; i < newsize; i++) {
            newstr[i + size] = s[i];
        }
        newstr[newsize] = '\0';
        
        size = newsize;
        delete[] str;
        str = newstr;
    }
    
    void operator =(String &s) {
        char* newstr = new char[s.getSize() +1];
        delete str;
        
        str = newstr;
        size = s.getSize();
        
        int i;
        for (i=0; i < size; i++) {
            str[i] = s[i];
        }
        str[i] = '\0';
    }
    
    // make friend, so we can access private members
    friend ostream& operator<< (ostream &out, String &s);
};



ostream& operator<< (ostream &out, String &s)
{
    for(int i=0; i<s.size; i++) {
        out << s.str[i];
    }
    return out;
}

int main(int argc, const char * argv[])
{
    String s1;
    String s2("String2");
    String s3("String3");
    String s4('.');
    s2 = s3;
    s2 += s4;

    
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
};
