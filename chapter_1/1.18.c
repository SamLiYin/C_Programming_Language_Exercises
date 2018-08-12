#include "stdio.h"
#include "stdlib.h"
#include <limits.h>
#define MAXLINE   1024

int get_line(char s[], int len);

int main()
{
	int len;
	int max;
	char line[MAXLINE];

	while((len = get_line(line, MAXLINE)) >= 0){
		if(len == 0)
			continue;

		printf("%d, %s\n", len, line);
	}

	return 0;
}

// line format
//\n
//    \n
//***\n
//***    \n
int get_line(char line[], int len)
{
	int c, i;

	for(i = 0; i < len && (c = getchar()) != EOF && c != '\n'; i++){
		line[i] = c;
	}

	// end with EOF or input line too long
	if(i >= len || c == EOF){
		printf("exit i = %d%s\n", i, c == EOF ? ", c == EOF" : "");
		return EOF;
	}

	// delete space and tab
	while(i > 0 && (line[i - 1] == ' ' || line[i - 1] == '\t')){
		i--;
	}

	if(i > 0 && c == '\n'){
		line[i] = '\n';
		i++;
	}

	line[i] = '\0';
	
	return i;
}
