#include <stdio.h>

const int mod = 15746;
 
long long cache[1000001][2];
 
int main(){

    int n = 0;
    scanf("%d", &n);

    cache[1][1] = 1;
    cache[2][1] = 1;
    cache[2][0] = 1;

    for(int i=3; i<=n; i++){
        cache[i][0] = (cache[i-2][0]%mod + cache[i-2][1]%mod) % mod; 
        cache[i][1] = (cache[i-1][1]%mod + cache[i-1][0]%mod) % mod;
    }

    long long ans = cache[n][0]%mod + cache[n][1] % mod;

    printf("%lld", ans%mod);

    return 0;
}
