
// Testrahmen fuer 1. Teilaufgabe

#include "RE.h"
#include "FSA.h"

#include "TestOrakel.h"

#include <iostream>
#include <string>

using namespace std;


// Systematischer Test

// Ein Testfall besteht aus einem regulaeren Ausdruck (RE)
// und einem Eingabestring.
// 
// Testorakel match ueberprueft ob string s enthalten in regex r.
// 
// Simplifizierer korrekt fuer Testfall, falls Testorakel gleiches
// Ergebnis liefert fuer Original regex r und simplifizierten regex r->simp()

bool testSimp(RE* r, string s)
{
    bool b = (match(r,s) == match(r->simp(),s));
    
    cout << "Test case: " << r->pretty() << "   " << s << "\n";
    cout << "Test result: " << b << endl;

    return b;
}

int main()
{
    cout << "Ein paar Testfaelle. Ueberpruefung per Auge" << endl;
    
    RE* r3 = new Alt (new Phi(), new Ch('c'));
    cout << "original:    " << r3->pretty() << endl;
    cout << "vereinfacht: " << r3->simp()->pretty() << endl;
    cout << "-----" << endl;
    
    RE* r4 = new Alt (new Ch('c'), new Phi());
    cout << "original:    " << r4->pretty() << endl;
    cout << "vereinfacht: " << r4->simp()->pretty() << endl;
    cout << "-----" << endl;
    
    RE* r5 = new Star(new Star (new Ch('c')));
    cout << "original:    " << r5->pretty() << endl;
    cout << "vereinfacht: "  << r5->simp()->pretty() << endl;
    cout << "-----" << endl;
    
    RE* r6 = new Star(new Phi());
    cout << "original:    " << r6->pretty() << endl;
    cout << "vereinfacht: " << r6->simp()->pretty() << endl;
    cout << "-----" << endl;

    RE* r7 = new Alt(new Ch('c'), new Ch('c'));
    cout << "original:    " << r7->pretty() << endl;
    cout << "vereinfacht: " << r7->simp()->pretty() << endl;
    cout << "-----" << endl;
    
    RE* r8 = new Alt(new Alt(new Ch('c'), new Ch('c')), new Phi());
    cout << "original:    " << r8->pretty() << endl;
    cout << "vereinfacht: " << r8->simp()->pretty() << endl;
    cout << "-----" << endl;
    
    RE* r9 = new Conc(new Eps(), new Ch('c'));
    cout << "original:    " << r9->pretty() << endl;
    cout << "vereinfacht: " << r9->simp()->pretty() << endl;
    cout << "-----" << endl;
    
    RE* r10 = new Conc(new Ch('c'), new Eps());
    cout << "original:    " << r10->pretty() << endl;
    cout << "vereinfacht: " << r10->simp()->pretty() << endl;
    cout << "-----" << endl;
    
    RE* r11 = new Conc(new Phi(), new Ch('c'));
    cout << "original:    " << r11->pretty() << endl;
    cout << "vereinfacht: " << r11->simp()->pretty() << endl;
    cout << "-----" << endl;
    
    RE* r12 = new Conc(new Ch('a'), new Star(new Alt(new Ch('c'), new Eps())));
    cout << "original:    " << r12->pretty() << endl;
    cout << "vereinfacht: " << r12->simp()->pretty() << endl;
    cout << "-----" << endl;
    
    RE* r13 = new Star(new Alt(new Ch('c'), new Eps()));
    cout << "original:    " << r13->pretty() << endl;
    cout << "vereinfacht: " << r13->simp()->pretty() << endl;
    cout << "-----" << endl;
    

    
    
    
    cout << "Verwende testSimp" << endl;
    testSimp(r5, "ab");


}
