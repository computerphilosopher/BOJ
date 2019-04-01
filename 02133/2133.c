#include <stdio.h>
#include <string.h>

long long cache[31];
 
long long dp(int n){
     
    if(n == 0){
        return 1;
    }
     
    if(n % 2){
        return 0;
    }

    if(n == 2){
        return 3;
    }

    long long *ret = &cache[n];

    if(*ret != -1){
        return *ret;
    }
    
    *ret = 3*dp(n-2) + 2*dp(n-4);

    for(int i=6; i<=n; i++){
        *ret += dp(n-i)*2;
    }

    return *ret;
}
int main(){

    int n = 0;
    scanf("%d", &n);
    
    memset(cache, -1, sizeof(cache));

    printf("%lld", dp(n));

    return 0;
}
