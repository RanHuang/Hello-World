%{
#include <stdio.h>
#include <string.h>

void yyerror(const char *str)
{
    fprintf(stderr, "error: %s\n", str);
}

int main()
{
    FILE* infile;
	infile = fopen("config.file", "r");

	yyrestart(infile);

	yyparse();

	fclose(infile);
	return 0;
}

char address[10][80];
int addrCount = 0;
%}

%token ALLOW DENY OPEN_BARCE CLOSE_BARCE WORD ATSYM PERIODSYM 

%%

configs:
	| configs config
	;

config:
	allowed
	|
	denied
	;

allowed: ALLOW OPEN_BARCE targets CLOSE_BARCE
	{
		int i;
		printf("These addressed are allowed:\n");
		for(i=0; i<addrCount; i++){
			printf("\t%s\n", address[i]);
		}
		addrCount = 0;
	}
	;

denied: DENY OPEN_BARCE targets CLOSE_BARCE
	{
		int i;
		printf("These addresses are denied:\n");
		for(i=0; i<addrCount; i++){
			printf("\t%s\n", address[i]);
		}
		addrCount = 0;
	}
	;

targets:
	|
	targets email_address
	;

email_address:
	WORD ATSYM WORD PERIODSYM WORD
	{
		if(addrCount < 10){
			sprintf(address[addrCount++],"%s@%s.%s", $1, $3, $5);
			free($1); free($3); free($5);
		}
	}
	;
