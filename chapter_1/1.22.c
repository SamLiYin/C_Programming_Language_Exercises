#include "stdio.h"

#define MAXCOL 10
#define TABINC 8

char line[MAXCOL];

int exptab(int pos);
int findblnk(int pos);
int newpos(int pos);
void printl(int pos);

int main()
{
	int c, pos;

	pos = 0;
	while((c = getchar()) != EOF){
		line[pos] = c;

		if(c == '\t'){
			pos = exptab(pos);
		} else if(c == '\n'){
			printl(pos);
			pos = 0;
		} else if(++pos >= MAXCOL){
			findblnk(pos);
			printl(pos);
			pos = newpos(pos);
		}
	}

	return 0;
}


void printl(int pos)
{
	int i;
	for(i = 0; i < pos; ++i){
		putchar(line[i]); // putchar any char, include blank???
	}

	if(pos > 0){
		putchar('\n');
	}
}

int exptab(int pos)
{
	line[pos] = ' ';
	for(++pos; pos < MAXCOL && pos % TABINC != 0; ++pos){
		line[pos] = ' ';
	}

	if(pos < MAXCOL){
		return pos;
	} else {
		printl(pos);
		return 0;
	}
}

int findblnk(int pos)
{
	while(pos > 0 && line[pos - 1] != ' '){
		--pos;
	}
	if(pos == 0){
		return MAXCOL;
	} else {
		return pos;
	}
}

int newpos(int pos)
{
	int i, j;
	if (pos <= 0 || pos >= MAXCOL){
		return 0;
	} else {
		for (i = pos - 1; i < MAXCOL; ++i,++j){
			line[j] = line[i];
		}
		return j;
	}
}