#include <stdio.h>

int solve(char str[]){

    int check[10] = {0};

    int i = 0;

    int count = 1;

    while(str[i]){
        int num = str[i++] - '0';

        ++check[num];

        if(num == 6 || num == 9){
            if(check[6] + check[9] > count * 2){
                count++;
            }
        }
        else{
            if(check[num] > count){
                count++;
            }
        }
    }

    return count;
}

int main(){
    char str[10];
    scanf("%s", str);

    printf("%d", solve(str));

    return 0;
}
