%{ 
#include "global.h"
#include "y.tab.h"
%}
%option yylineno
%%
"->"                                        return ARROW;
,                                           return COMMA;
\(                                          return OPEN_PEREN;
\)                                          return CLOSE_PEREN;
\n                                          return NEWLINE;

[a-z]+                                      { yylval.str = strdup(yytext); return STRING; };
[0-9]+                                      { yylval.str = strdup(yytext); return INTEGER; };
[ \t]                                       ;
.                                           printf("unexpected character\n");
%%
int yywrap(void)
{
    return 1;    
}
