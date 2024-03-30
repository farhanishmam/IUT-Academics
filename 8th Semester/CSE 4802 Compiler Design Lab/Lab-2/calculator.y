%{
#include <stdio.h>
%}

%start list

%token NUMBER

%left '+' '-'	//addition and subtraction is left associativity
%left '/' '*' 	//multiplication and division is left associativity
%right '^'		//power is right associativity
%left UMINUS  /*supplies precedence for unary minus */


%%                   /* beginning of rules section */

list:                       /*empty */
         | list stat '\n'
         | list error '\n'
         {
           yyerrok;
         }
         ;

stat:    expr { printf("%d\n",$1); }
  
         ;

expr:    '(' expr ')' { $$ = $2; }
	 | expr '^' expr   { $$ = power($1, $3);  }
         | expr '*' expr   { $$ = $1 * $3;  }
         | expr '/' expr   { $$ = $1 / $3;  }
         | expr '+' expr  { $$ = $1 + $3;  }
         | expr '-' expr   { $$ = $1 - $3;  }
         | '-' expr %prec UMINUS { $$ = -$2; }
         | NUMBER  { $$ = $1; };

%%

int power(int base, int exponent) {
  
  if(exponent<0 && base != 1){
	return 0;	// for negative exponents return 0 
			// as they produce decimal values less than 1
  }
  int result = 1;
  int i;
  for (i = 0; i < exponent; i++) {
    result *= base;	
  }
   return result;
 
}



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