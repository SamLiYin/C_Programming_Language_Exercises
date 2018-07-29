#include <stdio.h>
#include "stdbool.h"

int main(){
    int c;
    int c_pre;
    bool cnt_flag = true;

    while((c = getchar()) != EOF){
        if(c == c_pre && c == ' '){
            cnt_flag = false;
        } else {
            cnt_flag = true;
        }

        if(cnt_flag){
            putchar(c);
        }
        c_pre = c;
    }  

    return 0;
}
