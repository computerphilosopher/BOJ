#include <stdio.h> 

long long memo[91];

long long fib(int n){

    if(n == 0){
        return 0;
    }

    else if(n == 1){
        return 1;
    }
    else if(n == 2){
        return 1;
    }

    else if(memo[n]){
        return memo[n];
    }

    else{
        memo[n] = fib(n-2) + fib(n-1);
        return memo[n];
    }
}

int main(){

    int n = 0;
    scanf("%d", &n);

    printf("%lld", fib(n));

    return 0;
}

