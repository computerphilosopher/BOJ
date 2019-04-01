#include <stdio.h>
#include <string.h>

int power(const int n, const int ex){

    int ret = 1;
     
    for(int i=0; i<ex; i++){
        ret *= n;
    }

    return ret;
}

int ctoi(const char c){

    if('0' <= c && c <= '9'){
        return c - '0';
    }

    return (c - 'A') + 10; 
}

int solve(const char str[], const int len, const int digit){

    int ret = 0;
     
    for(int i=0; i<len; i++){
         
        const int num = ctoi(str[len-1-i]);

        ret += num * power(digit, i);
    }

    return ret;
}

int main(){
    char input[100000] = {0};
    scanf("%s", input);

    int digit = 0;
    scanf("%d", &digit);

    printf("%d", solve(input, strlen(input), digit));

    return 0;
}
