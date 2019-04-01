#include <stdio.h>
#include <stdlib.h>

int get_digit(int n){

    int ret = 0;

    while(n){
        ret++;
        n /= 10;
    }

    return ret;
}

int main(){
    int n = 0;
    scanf("%d", &n);

    int ans = 0;

    for(int i=1; i<=n; i++){
        ans +=  get_digit(i);
    }

    printf("%d", ans);
    return 0;
}
