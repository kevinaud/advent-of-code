#include <stdio.h>
#include <iostream>
#include "global.h"

using namespace std;

extern int yylex();
extern int yylineno;
extern char* yytext;

int yyparse(void);

int main(void) {

    yyparse();
    
    /* int ntoken, vtoken; */

    /* ntoken = yylex(); */
    /* while (ntoken) { */
    /*     printf("%s\n", names[ntoken]); */
    /*     if (ntoken == SEMICOLON) { */
    /*         printf("\n"); */
    /*     } */
    /*     ntoken = yylex(); */
    /* } */

    return 0;
}
