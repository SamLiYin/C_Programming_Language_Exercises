#include "stdio.h"
#include "stdlib.h"
#include <limits.h>

#define MAXLINE  1024

int get_line(char s[], int len);
void copy_data(char d[], char s[]);

int main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while((len = get_line(line, MAXLINE)) > 0){
		printf("%d %s\n", len, line);

		if(len > max){
			max = len;
			copy_data(longest, line);
		}
	}
	
	if(max > 0)
		printf("%s\n", longest);

	return 0;
}

int get_line(char line[], int len)
{
	int c, i, j;

	j = 0; // to save the index in line array when exit from for loop
	for(i = 0; (c = getchar()) != EOF && c != '\n'; i++){
		if(i < len - 2){ // key point of this exercise
			line[j] = c;
			j++;
		}
	}

	if(c == '\n'){
		line[j] = '\n';
		j++;
		i++; //	do not forget to plus one to i 
	}

	line[j] = '\0';
	
	return i;
}

void copy_data(char *d, char *s){
	int i;

	i = 0;
	while((d[i] = s[i]) != '\0')
		i++;
}
