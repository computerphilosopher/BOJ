#include <stdio.h>
 
 
#include <stdlib.h>
#include <limits.h>

int min(int a, int b, int c){
    
    int arr[3] = {a, b, c};
    int min = arr[0];

    for(int i=0; i<3; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }

    return min;
}

int dp(int n, int cache[]){
    
    int a = INT_MAX;
    int b = INT_MAX;
    int c = INT_MAX;

    if(cache[n]){
        return cache[n];
    }
    
    if(n == 1){
        return 0;
    }

    if(n%3 == 0){
         a = dp(n/3, cache);
    }

    else if(n%2 == 0){
         b = dp(n/2, cache);
    }

    if(n > 1){
         c = dp(n-1, cache);
    }

    cache[n] = 1 + min(a, b, c);

    return cache[n];

}

int main(){

    int n = 0;

    scanf("%d",&n);

    int *cache = (int*)calloc(n+1, sizeof(int));

    printf("%d", dp(n,cache));
}
