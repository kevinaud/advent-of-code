%{
#include <stdio.h>
#include <iostream>
#include "global.h"

int yylex(void);
void yyerror(char *);
%}

%union {
    char* str;    
}
# %token ALPHABET START FINAL SEMICOLON COLON END COMMA
# %token <str> IDENTIFIER CHAR STATE STATE_TRANSITION
# %type <str> id
# %start start

%%

# start: start stateMachine 
#      |
#      ;

# stateMachine: nameDef alphabetDef statesDef END {
#                     cout << stateMachine.generateSubroutine() << endl;
#                 }
#             ;

# nameDef: id COLON { 
#                         stateMachine = StateMachine();
#                         stateMachine.setName($1);
#                   }
#        ;

# id: IDENTIFIER
#   | CHAR
#   ;

# alphabetDef: ALPHABET charList SEMICOLON
#            ;

# charList: CHAR { stateMachine.addAlphabetChar($1[0]); }
#         | CHAR COMMA charList { stateMachine.addAlphabetChar($1[0]); }
#         ;

# statesDef: startDef stateList
#          ;

# startDef: START id SEMICOLON { stateMachine.setStart($2); }
#         ;

# stateList: stateDef
#          | stateDef stateList
#          ;

# stateDef: STATE id transitionList SEMICOLON {
#                 stateMachine.addState($2);
#                 stateMachine.setTransitions($2, transitions);
#                 transitions.clear();
#             }
#         | FINAL id transitionList SEMICOLON {
#                 stateMachine.setFinal($2);
#                 stateMachine.addState($2);
#                 stateMachine.setTransitions($2, transitions);
#                 transitions.clear();
#             }
#         ;

# transitionList: STATE_TRANSITION { 
#                                     string transition($1);
#                                     transitions.push_back(transition);
#                                  }
#               | STATE_TRANSITION COMMA transitionList { 
#                                     string transition($1);
#                                     transitions.push_back(transition);
#                                  }
#               ;


%%
void yyerror(char *msg)
{
   fprintf(stderr,"%s, line number: %d\n", msg, yylineno);
}
