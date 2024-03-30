%{
// declaration
int wc = 0;	//word counter
int nc = 0;	//number counter
int cc = 0;	//total character counter
%}

%%
[\t ]+       ;
[a-zA-Z]+     {wc++;cc+=yyleng;}
[+-]?([0-9]*[.])?[0-9]+ {nc++;cc+=yyleng;}
. {cc+=yyleng;}

%%
// Subroutines
int main(int argc, char *argv[])
{
	yyin = fopen(argv[1], "r");
	yylex();
	fclose(yyin);
	printf("Words: %d, Numbers: %d, Total Characters: %d", wc,nc, cc);
}

int yywrap() { return 1; }
