
// Testrahmen fuer 1. Teilaufgabe

#include <iostream>

using namespace std;

#include "FSA.h"
#include "RE.h"

#include "Transform.h"
#include "TestOrakel.h"

#include <string>



//--------------------------- TEIL 1 ---------------------------
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

//--------------------------- TEIL 2 UND 3 ---------------------------
// Systematischer Test

// Ein Testfall besteht aus einem regulaeren Ausdruck (RE)
// und einem Eingabestring.
//
// Testorakel match ueberprueft ob string s enthalten in regex r.
//
// closure und Tranformater RE -> NFA korrekt, falls Testorakel gleiches
// Ergebnis liefert wie Ausfuehrung des resultierenden NFA.

bool testClosureTransform(RE* r, string s) {
    NFA nfa = transform(r);
    FSA fsa(nfa);
    bool b1 = fsa.run(s);
    bool b2 = match(r,s);
    bool b = b1 == b2;
    
    cout << "fsa.run: " << b1 << endl;
    
    cout << "deriv: " << b2 << endl;

    
    cout << "Test case: " << r->pretty() << "   " << s << "\n";
    cout << "Test result: " << b << endl;
    
    return b;
}



int main()
{
    //TESTE TEIL 1
    cout << "---------- TEIL 1 ----------" << endl;
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
    
    
    RE* r13 = new Conc(new Eps(), new Conc(new Star(new Star(new Ch('a'))), new Alt(new Phi(), new Ch('b')))); //eps ((a*)* (phi + b))
    cout << "original:    " << r13->pretty() << endl;
    cout << "vereinfacht: " << r13->simp()->pretty() << endl;
    cout << "-----" << endl;
    
    //TESTE TEIL 2 UND 3
    cout << "---------- TEIL 2 UND 3 ----------" << endl;
    RE* r14 = new Conc(new Alt(new Ch('a'), new Ch('b')), new Ch('a'));

    NFA test = transformWorker(r14);
    
    cout << "Initial: " << test.getInitial() << endl;
    
    for(int i = 0; i< test.getFinals().size(); i++ ) {
        cout << "Finals: " << test.getFinals()[i] << endl << endl << "Transitions: " << endl;
    }
    
    for(int i = 0; i< test.getTransitions().size(); i++ ) {
        cout << "From: " << test.getTransitions()[i].getFrom() << endl;
        cout << "-With: " << (char) test.getTransitions()[i].getChar() << endl;
        cout << "To: " << test.getTransitions()[i].getTo() << endl;
        cout << "-----" << endl;
    }
    
    //testClosureTransform(r14, "aa");
}
