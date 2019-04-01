#include <stdio.h>
 

int cache[1001];

int count(int n){

    
    if(n <= 1){
        return 1;
    }

    int *ret = &cache[n];

    if(*ret){
        return *ret;
    }

    return *ret = (count(n-1) + count(n-2)) % 10007;
}

int main(){

    int n = 0;
    scanf("%d", &n);

    printf("%d", count(n));
}
