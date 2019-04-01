#include <stdio.h>
#include <algorithm>
 
#define MOD 1000000000
 
using namespace std;

long long cache[101][10];

long long solve(int n, int k){

    if(k>9 || k<0){
        return 0;
    }

    if(n == 1){
        if(k == 0){
            return 0;
        }
        else{
            return 1;
        }
    }

    long long &ret = cache[n][k];

    if(ret != -1){
        return ret;
    }

    return ret = ( solve(n-1, k-1) + solve(n-1, k+1) ) % MOD;
}

int main(){

    int n = 0;

    scanf("%d", &n);

    long long ans = 0;

    for(int i=0; i<101; i++){
        fill(cache[i], cache[i]+10, -1);
    }

    for(int i=0; i<=9; i++){
        ans = (ans + solve(n, i))%MOD;
    }

    printf("%lld", ans);
}
