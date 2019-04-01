#include <stdio.h>

int solve(int coins[], int n, int k){

    for(int i=n-1; i>=0; i--){
        if(coins[i] == k){
            return 1;
        }
        else if(coins[i] < k){
            return 1 + solve(coins, n, k-coins[i]);
        }
    }
}

int main(){

    int n = 0;
    int k = 0;

    scanf("%d %d", &n, &k);

    int coins[n];

    for(int i=0; i<n; i++){
        scanf("%d", &coins[i]);
    }

    printf("%d", solve(coins, n, k));

    return 0;
}
