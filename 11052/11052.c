#include <stdio.h>

int price[1001];
int cache[1001];

int profit(int n){

    if(n <= 0 ){
        return 0;
    }

    if(cache[n]){
        return cache[n];
    }

    int arr[n+1];

    arr[0] = 0;

    for(int i=1; i<=n; i++){
        arr[i] = (price[i]) + profit(n-i);
    }

    int max = -1;
    for(int i=1; i<=n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

   return cache[n] = max;

}

int main(){

    int n = 0;
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        scanf("%d", &price[i]);
    }

    printf("%d", profit(n));

}
