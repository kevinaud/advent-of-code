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

%token ARROW COMMA OPEN_PEREN CLOSE_PEREN NEWLINE
%type <str> STRING INTEGER
%start towerList
%%

towerList: tower towerList 
     |
     ;

tower: STRING towerWeight dependencies {
        cout << $1 << endl; 
    };

towerWeight: OPEN_PEREN INTEGER CLOSE_PEREN {
        cout << "(" << $2 << ") "; 
    };

dependencies: ARROW dependencyList
            |
            ;

dependencyList: STRING COMMA dependencyList { cout << $1 << ", "; }
              | STRING NEWLINE { cout << $1; }
              ;

%%
void yyerror(char *msg)
{
   fprintf(stderr,"%s, line number: %d\n", msg, yylineno);
}
