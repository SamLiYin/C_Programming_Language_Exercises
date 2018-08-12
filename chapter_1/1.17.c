#include "stdio.h"
#include "stdlib.h"
#include <limits.h>

#define MAXLINE         1024
#define MAX_OUTPUT_LINE 80

int get_line(char s[], int len);

int main()
{
	int len;
	char line[MAXLINE];

	while((len = get_line(line, MAXLINE)) > 0){
		if(len > MAX_OUTPUT_LINE){
			printf("%d\n%s\n", len, line);

			if(len > MAXLINE){
				printf("len of input line exceed MAXLINE\n");
			}
		}
	}

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
