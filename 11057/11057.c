#include <stdio.h>
 
#include <string.h>

int cache[1001][10];

const int mod = 10007;
 
long long dp(int n, int k){

    if(n == 1){
        return n ? 1 : 0;
    }
    
    int *ret = &cache[n][k];

    if(*ret != -1){
        return *ret;
    }

    *ret = 0;

    for(int i=k; i>=0; i--){
        *ret += dp(n-1, i);
    }

    return (*ret)%10007;
}

int main(){
    int n = 0;
    scanf("%d", &n);

    memset(cache, -1, sizeof(cache));

    long long ans = 0;

    for(int i=0; i<10; i++){
        ans += dp(n, i); 
    }

    printf("%lld", ans % 10007);

    return 0;
}
