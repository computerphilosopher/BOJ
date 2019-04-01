#include <stdio.h>

int solve(char str[]){

    int i = 0;
    int ret = 0;

    while(str[i]){

        char c = str[i++];

        if('A' <= c && c <= 'C'){
            ret += 3;
        }
        
        else if('D' <= c && c <= 'F'){
            ret += 4;
        }
        
        else if('G' <= c && c <= 'I'){
            ret += 5;
        }
        
        else if('J' <= c && c <= 'L'){
            ret += 6;
        }
        
        else if('M' <= c && c <= 'O'){
            ret += 7;
        }
        
        else if('P' <= c && c <= 'S'){
            ret += 8;
        }
        
        else if('T' <= c && c <= 'V'){
            ret += 9;
        }
        
        else if('W' <= c && c <= 'Z'){
            ret += 10;
        }
    }

    return ret;
}
int main(){
    char str[16];
    scanf("%s", str);

    printf("%d", solve(str));
}
