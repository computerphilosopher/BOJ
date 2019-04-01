#include <stdio.h>
 
#include <string.h>
 
#define MOD 1000000000
 

int cache[101][10];

int solve(int n, int k){

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

    int *ret = &cache[n][k];

    if(*ret != -1){
        return *ret;
    }

    return *ret = ( solve(n-1, k-1) + solve(n-1, k+1) ) % MOD;
}

int main(){

    int n = 0;

    scanf("%d", &n);

    int ans = 0;

    memset(cache, -1, sizeof(cache));

    for(int i=0; i<=9; i++){
        ans = (ans + solve(n, i))%MOD;
    }

    printf("%d", ans);
}
