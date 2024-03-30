%option noyywrap

%{
#include <stdio.h>
#include "y.tab.h"
extern int yylval;	
%}

%%
[\t ]+       ;
[a-z]     {
            yylval = yytext[0];	//Only alphabets are allowed as identifiers
            return(LETTER);
          }
[0-9]+     {
	    yylval = atoi(yytext);
            return(NUMBER);
          }

[^a-z0-9\b]    {
                 return(yytext[0]);
               }

%%