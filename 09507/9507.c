#include <stdio.h>

long long cache[68];

long long fib(int n){

    if(n<2){
        return 1;
    }

    if(n == 2){
        return 2;
    }
    
    if(n == 3){
        return 4;
    }

    long long *ret = &cache[n];

    if(*ret){
        return *ret;
    }
    return *ret = fib(n-1) + fib(n-2) + fib(n-3) + fib(n-4);
}

int main(){

    int t = 0;
    scanf("%d", &t);

    for(int i=0; i<t; i++){
        int n = 0;
        scanf("%d", &n);
        printf("%lld\n", fib(n));
    }

    return 0;
}
