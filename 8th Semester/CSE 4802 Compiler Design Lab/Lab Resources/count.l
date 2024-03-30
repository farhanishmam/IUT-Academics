%{
// declaration
%}

%%
[\t ]+       ;
[a-zA-Z]+     {printf("%s :word\n",yytext);}
[+-]?([0-9]*[.])?[0-9]+ {printf("%s : number\n",yytext);}
. {printf("%s : unknown\n",yytext);}

%%
// Subroutines
int main()
{
printf("Enter a string: ");
yylex();
}

int yywrap() { return 1; }
