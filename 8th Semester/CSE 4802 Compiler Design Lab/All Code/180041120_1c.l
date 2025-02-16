%{
// declaration
int wc = 0;	//word counter
int nc = 0;	//number counter
int cc = 0;	//character counter

#undef yywrap	//yywrap is a macro defined by default
%}

%%
[\t ]+       ;
[a-zA-Z]+     {wc++; cc+=yyleng;}
[+-]?([0-9]*[.])?[0-9]+ {nc++;cc+=yyleng;}
. {cc+=yyleng;}

%%
// Subroutines
char **fileList;
int currentFile = 0;
int nFiles;
int totalWC = 0;	//total word counter
int totalNC = 0;	//total number counter
int totalCC = 0;	//total character counter

int main(int argc, char *argv[])
{	
	printf("file_name words, numbers, characters\n");

	FILE *file;	

	fileList =  argv+1;
	nFiles = argc-1;

	if(argc == 2){
		// We handle single file case differently from multiple files
		// Because we don't need to print a summary for single file
		currentFile = 1;
		file = fopen(argv[1], "r");
		
		yyin = file;
	}

	
	if(argc > 2){
		yywrap(); //opens first file
	}
	yylex();

	if(argc > 2){
		printf("%s %d, %d, %d\n", fileList[currentFile-1], wc, nc, cc);
		totalWC += wc;
		totalNC += nc;
		totalCC	+= cc;
		printf("total %d, %d, %d\n",totalWC, totalNC, totalCC);
	}
	else{
		printf("%d, %d, %d\n", wc, nc, cc);
	}
	return 0;
}

int yywrap() 
{ 
	FILE *file;
	if ((currentFile!=0) && (nFiles>1) && (currentFile < nFiles)){
		printf("%s %d, %d, %d\n", fileList[currentFile-1], wc, nc, cc);
		totalWC += wc;
		totalNC += nc;
		totalCC	+= cc;
		wc = nc = cc = 0;
		fclose(yyin);
	}
	while (fileList[currentFile] != NULL){
		file = fopen(fileList[currentFile++],"r");
		if(file != NULL){
			yyin = file;
			return 0;
		}	
	}
	return 1;
}
