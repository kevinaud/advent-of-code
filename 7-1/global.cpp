#include "global.h"

StateMachine stateMachine;
vector<string> transitions;

StateMachine::StateMachine()
{

}

string StateMachine::generateSubroutine()
{
    string subroutine = "";

    subroutine += "bool " + name + "(char input)\n";
    subroutine += "{\n";
    subroutine += "\tenum StateList {" + this->getStateList() + "};\n";
    subroutine += "\tstatic StateList State = " + startState + ";\n\n";
    subroutine += "\tif (input == '\\0') {\n";
    subroutine += "\t\tState = " + startState + ";\n";

    if (startState == finalState) {
        subroutine += "\t\treturn true;\n";
    } else {
        subroutine += "\t\treturn false;\n";
    }
    
    subroutine += "\t}\n\n";
    subroutine += "\tswitch (State) {\n";

    for (vector<string>::iterator it = states.begin(); it != states.end(); ++it) {
        subroutine += this->generateStateSwitchCase(*it);
    }

    subroutine += "\t}\n";
    subroutine += "}\n";

    return subroutine;
}

string StateMachine::generateStateSwitchCase(string state)
{
    string switchCase = "\t\tcase " + state + ":\n"; 

    switchCase += "\t\tswitch (input) {\n";

    for (vector<char>::iterator it = alphabet.begin(); it != alphabet.end(); ++it) {
        switchCase += this->generateActionSwitchCase(state, *it);
    }

    switchCase += "\t\t}\n";
    switchCase += "\t\tbreak;\n\n";

    return switchCase;
}

string StateMachine::generateActionSwitchCase(string state, char action)
{
    string nextState = this->getNextState(state, action);
    string switchCase = "\t\t\tcase '"; 
    
    switchCase += action;
    switchCase += "':\n";
    switchCase += "\t\t\tState = " + nextState + ";\n";

    if (nextState == finalState) {
        switchCase += "\t\t\treturn true;\n\n";
    } else {
        switchCase += "\t\t\treturn false;\n\n";
    }

    return switchCase;
}

void StateMachine::addAlphabetChar(char c)
{
    alphabet.push_back(c);
}

void StateMachine::addState(string state)
{
    states.push_back(state);
}

void StateMachine::setTransitions(string state, vector<string> transitions)
{
    vector<string>::iterator it;
    for (it = transitions.begin(); it != transitions.end(); ++it) {
        string transition = *it;

        // remove parens
        transition = transition.substr(0, transition.size() - 1); 
        transition = transition.substr(1, transition.size()); 

        stringstream ss(transition);
        string transitionAction;
        string transitionState;

        getline(ss, transitionAction, ',');
        getline(ss, transitionState, ',');

        this->addTransition(state, transitionAction[0], transitionState);
    }
}

void StateMachine::addTransition(string start, char action, string end)
{
    transitions[start][action] = end;
}

string StateMachine::getNextState(string start, char action)
{
    return transitions[start][action];
}

string StateMachine::getStateList()
{
    string stateList = "";
    for (vector<string>::iterator it = states.begin(); it != states.end(); ++it) {
        stateList += *it + ",";
    }
    if (stateList.size() > 0) {
        stateList = stateList.substr(0, stateList.size() - 1); 
    }
    return stateList;
}

string StateMachine::getName()
{
    return name;
}

void StateMachine::setName(string name)
{
    this->name = name;
}

string StateMachine::getStart()
{
    return startState;
}

void StateMachine::setStart(string startState)
{
    this->startState = startState;
}

string StateMachine::getFinal()
{
    return finalState;
}

void StateMachine::setFinal(string finalState)
{
    this->finalState = finalState;
}
