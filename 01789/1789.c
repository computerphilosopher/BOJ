#include <stdio.h>

long long solve(long long n){

    long long i = 1;
    long long k = 0;

    while(1){

        k += i;
        if(k >= n){
            break;
        }
        i++;
    }

    return (k == n) ? i : i-1;
}

int main(){

    long long n = 0;

    scanf("%lld", &n);

    printf("%lld", solve(n));

    return 0;
}
