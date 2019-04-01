#include <stdio.h>

int f(int a, int b){

    if(a == 0){
        return b;
    }

    int sum = 0;

    for(int i=1; i<=b; i++){
        sum += f(a-1, i);
    }

    return sum;
}

int main(){

    int t = 0;
    scanf("%d", &t);

    for(int i=0; i<t; i++){
        int k = 0;
        int n = 0;

        scanf("%d %d", &k, &n);

        printf("%d\n", f(k, n));
    }
}
