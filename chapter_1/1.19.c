#include "stdio.h"
#include "stdlib.h"
#include <limits.h>
#define MAXLINE   1024

void reverse(char s[], int len);
int get_line(char s[], int len);

int main()
{
	int len;
	int max;
	char line[MAXLINE];

	while((len = get_line(line, MAXLINE)) >= 0){
		if(len == 0)
			continue;
		reverse(line, len);

		printf("%d,%s\n", len, line);
	}

	return 0;
}

void reverse(char s[], int len)
{
	int mid;
	char c;

	if(len <= 1)
		return;

	mid = len / 2;
	for(int i = 0; i < mid; i++){
		c = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = c;
	}
	return;
}

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

	line[i] = '\0';
	
	return i;
}
