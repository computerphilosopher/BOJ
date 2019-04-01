#include <stdio.h>
 

int cache[1001];

int tilling(int n){

    if(n<0){
        return 0;
    }
    if(n == 1 || n == 0){
        return 1;
    }

    if(cache[n]){
        return cache[n]; 
    }

    return cache[n] = (tilling(n-1)+ (2 *tilling(n-2))) % 10007;
}

int main(){

    int n = 0;

    scanf("%d", &n);

    printf("%d", tilling(n));
}
