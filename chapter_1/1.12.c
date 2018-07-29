#include <stdio.h>

#define WORD_IN 1
#define WORD_OUT 0

int main(){
    int c;
    int state;

    state = WORD_OUT;
    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\t' || c == '\n'){
            if(state == WORD_IN){
                putchar('\n');
            }
            state = WORD_OUT;
        } else if(state == WORD_OUT){
            state = WORD_IN;
        }
        
        if(state == WORD_IN){
            putchar(c);
        }
    }
    
    return 0;
}
