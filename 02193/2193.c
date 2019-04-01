#include <stdio.h>

long long memo[91];

long long pinary(int n){

    long long *ret = &memo[n];

    if(*ret){
        return *ret;
    }

    else if(n==0){
        return 1;
    }
    else if(n == 1){
        return 0;
    }

    else if(n == 2){
        return 1;
    }

    return *ret = pinary(n-1) + pinary(n-2);

}

int main(){

    int n = 0;
    scanf("%d", &n);

    printf("%lld", pinary(n) + pinary(n-1));

}
