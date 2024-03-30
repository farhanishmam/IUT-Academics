%{
// declaration
int wc = 0;	//word counter
int nc = 0;	//number counter
int cc = 0;	//total character counter
%}

%%
[\t ]+       ;
[a-zA-Z]+     {printf("%s :word\n",yytext);wc++;cc+=yyleng;}
[+-]?([0-9]*[.])?[0-9]+ {printf("%s : number\n",yytext);nc++;cc+=yyleng;}
. {printf("%s : unknown\n",yytext);cc+=yyleng;}

%%
// Subroutines
int main()
{
printf("Enter a string: ");
yylex();
printf("Words: %d, Numbers: %d, Total Characters: %d", wc,nc, cc);
}

int yywrap() { return 1; }
