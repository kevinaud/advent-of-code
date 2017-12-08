#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

class StateMachine
{
public:
    StateMachine();

    string generateSubroutine();
    
    void addAlphabetChar(char c);
    void addState(string state);

    string getNextState(string current, char action);
    void setTransitions(string state, vector<string> transitions);

    string getName();
    void setName(string name);

    string getStart();
    void setStart(string startState);

    string getFinal();
    void setFinal(string finalState);

protected:
    string name;
    string startState;
    string finalState;
    vector<char> alphabet;
    vector<string> states;
    map<string, map<char, string> > transitions;

    void addTransition(string start, char action, string end);
    string getStateList();
    string generateStateSwitchCase(string state);
    string generateActionSwitchCase(string state, char action);
};

extern StateMachine stateMachine;
extern vector<string> transitions;
extern int yylineno;
