#include <stdio.h>

#define WORD_MAX 26
#define EXTRA_LEN 3

void print_vertical(int data[], int cnt){
    int max_len = 0;

    for(int i = 0; i < cnt; i++){
        if(max_len < data[i]){
            max_len = data[i];
        }
    }

    printf("\n\t^\n");
    printf("\t|\n");

    for(int j = max_len; j >= 0; j--){
        printf("\t|");
        for(int k = 0; k < cnt; k++){
            if(data[k] == j){
                printf(" %2d", data[k]);
            } else if(data[k] > j){
                printf(" **");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }

    printf("\t+");
    for(int i = 0; i < cnt + 1; i++){
        printf("---");
    }
    printf("--> max_len: %d\n", max_len);
}

int main(){
    int c;
    int data[WORD_MAX] = {0};

    while((c = getchar()) != EOF){
        if(c < 'a' || c > 'z'){
            continue;
        } else {
            putchar(c);
            data[c - 'a']++;
        }
        
    }

    print_vertical(data, WORD_MAX);

    return 0;
}
