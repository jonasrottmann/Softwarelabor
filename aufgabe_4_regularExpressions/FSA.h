
// Endliche Automaten

#ifndef __FSA__
#define __FSA__

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Transition;
class NFA;
class FSA;



class Transition
{
private:
    int from;
    char c;
    int to;
    bool epsilon;
public:
    
    Transition(int _from, int _to)
    {
        from = _from; to = _to;
        epsilon = true;
    }
    Transition(int _from, char _c, int _to)
    {
        from = _from; c = _c; to = _to;
        epsilon = false;
    }
    bool isEpsilonTransition()
    {
        return epsilon;
    }
    int toState()
    {
        return to;
    }
    bool trigger(int from, char c)
    {
        return (!epsilon && from == this->from && c == this->c);
    }
    bool trigger(int from)
    {
        return (epsilon && from == this->from);
    }
    
    //Hinzugefügt
    int getFrom() {
        return from;
    }
    int getChar() {
        return c;
    }
};

class NFA
{
private:
    vector<Transition> ts;
    int init;
    vector<int> final;
    
public:
    NFA(vector<Transition> _ts, int _init, vector<int> _final)
    {
        ts = _ts;
        init = _init;
        final = _final;
    }
    NFA(vector<Transition> _ts, int _init, int _final)
    {
        ts = _ts;
        init = _init;
        final.push_back(_final);
    }
    vector<Transition> getTransitions()
    {
        return ts;
    }
    int getInitial()
    {
        return init;
    }
    vector<int> getFinals()
    {
        return final;
    }
    
    friend class FSA;
};

class FSA : public NFA
{
private:
    vector<int> current;
    void closure();
public:
    FSA(NFA fsa) : NFA(fsa.ts,fsa.init,fsa.final)
    {
        current.push_back(init);
        closure();
    }
    void debugout();
    void reset();
    void step(char c);
    bool isFinal();
    bool run(string s);
    
};

void FSA::reset()
{
    current.clear();
    current.push_back(init);
    closure();
}

bool FSA::isFinal()
{
    for(int i=0; i < final.size(); i++)
    {
        if(find(current.begin(),current.end(),final[i]) != current.end()) {
            return true;
        }
    }
    return false;
}

void FSA::closure() //sammelt alle zustände in current, die vom aktuellen zustand mit epsilon-transitions erreichbar sind
{
    for(int i = 0; i < current.size(); i++) //durchläuft alle zustände in current
    {
        for(int j=0; j < ts.size(); j++)  //alle übergänge durchlaufen
        {
            if(ts[j].trigger(current[i])) //übergang startet von hier
            {
                if(find(current.begin(),current.end(),ts[j].toState()) == current.end()) // Übergang noch nicht in current
                {
                    current.push_back(ts[j].toState()); //ziel des übergangs zu current hinzufügen
                }
            }
        }
    }
}

void FSA::step(char c)
{
    vector<int> next;
    for(int i=0; i < ts.size(); i++)    // durchlaeuft alle Uebergaenge
    {
        for (int j=0; j < current.size(); j++)  // durchlaeuft alle aktiven Zustaende
        {
            if(ts[i].trigger(current[j],c))
            {
                next.push_back(ts[i].toState());
            }
        }
    }
    current = next;
    closure();
}

bool FSA::run(string s)
{
    reset();
    for(int i=0; i < s.length(); i++)
    {
        step(s[i]);
    }
    return isFinal();
}

#endif // __FSA__
