#include <stdio.h>

#define WORD_IN 1
#define WORD_OUT 0
#define WORD_MAX 20
#define EXTRA_LEN 3

void print_horizontal(int data[], int cnt){
    int max_len = 0;

    printf("\t^\n");
    printf("\t|\n");
    
    max_len = data[0];
    for(int i = 0; i < cnt; i++){
        printf("\t|");
        for(int j = 0; j < data[i]; j++){
            printf("*");
        }
        printf("(%d)\n", data[i]);

        if(data[i] > max_len){
            max_len = data[i];
        }
    }

    printf("\t+");
    for(int k = 0; k < max_len + EXTRA_LEN; k++){
        printf("-");
    }
    printf("--> max_len: %d\n\n", max_len);
}

int main(){
    int c;
    int state, w_cnt;
    int data[WORD_MAX] = {0};

    state = WORD_OUT;
    w_cnt = 0;
    while((c = getchar()) != EOF && w_cnt < WORD_MAX){
        if(c == ' ' || c == '\t' || c == '\n'){
            if(state == WORD_IN){
                putchar('\n');
                w_cnt++;
            }
            state = WORD_OUT;
        } else if(state == WORD_OUT){
            state = WORD_IN;
        }
        
        if(state == WORD_IN){
            putchar(c);
            data[w_cnt]++;
        }
    }

    print_horizontal(data, w_cnt);   
    return 0;
}
