%option noyywrap

%{
#include <stdio.h>
#include "y.tab.h"
int c;
extern int yylval;
%}

%%
" "       ;

[0-9]+     {
	    yylval = atoi(yytext);
            return(NUMBER);
          }

[^a-z0-9\b]    {
                 return(yytext[0]);
               }

%%