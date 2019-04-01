#include <stdio.h>
#include <stdbool.h>

int divisor(int n){

    int count = 0;
    for(int i = 1; i<=n; i++){
        if(n % i == 0){
            count++;
        }
    }
    return count;
}


int solve(int n){

    int ret = 0;

    for(int i=1; i<=n; i++){
        bool b = (divisor(i) % 2 == 0) ? false:true;

        if(b){
            ret++;
        }

    }

    return ret;
}

int main(){

    int t = 0;
    scanf("%d", &t);

    for(int i=0; i<t; i++){
        int n = 0;
        scanf("%d", &n);

        printf("%d\n", solve(n));
    }
}
