#include <stdio.h>

int main(){
    int c, cnt;

    cnt = 0;
    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\t' || c == '\n')
            cnt++;
    }
    printf("cnt: %d\n", cnt); 
    return 0;
}
