#include <stdio.h>
#include "stdbool.h"

int main(){
    int c;
    int c_next;

    while((c = getchar()) != EOF){
        switch(c){
            case '\t':
                c = '\\';
                putchar(c);
                c = 't';
                putchar(c);
                break;
            case '\b':
                c = '\\';
                putchar(c);
                c = 'b';
                putchar(c);
                break;
            case '\\':
                c = '\\';
                putchar(c);
                putchar(c);
                break;
            default:
                putchar(c);
        }
    }  

    return 0;
}
