%{
#include <stdio.h>

%}

%start list

%token NUMBER

%left '+' '-'
%left '*' '/' '%'

%%                   /* beginning of rules section */

list:                       /*empty */
         | list stat '\n'
         | list error '\n'
         {
           yyerrok;
         }
         ;

stat:    expr
         {
           printf("\n");
         };

expr:    '(' expr ')' 
         | expr '*' expr   { printf("* ");}
         | expr '/' expr   { printf("/ ");}
         | expr '%' expr { printf("% ");}
         | expr '+' expr  { printf("+ ");}
         | expr '-' expr   { printf("- ");}
         | NUMBER  { printf("%d ",yylval);} ;


%%
main()
{
 return(yyparse());
}

yyerror(s)
char *s;
{
  fprintf(stderr, "%s\n",s);
}

yywrap()
{
  return(1);
}