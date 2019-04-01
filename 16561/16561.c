#include <stdio.h>

int solve(const int n, const int depth){

    if(depth == 3){
        return n>0 && n%3==0;
    }

    int ret = 0;

    for(int i=1; i*3 <= n; i++){

        const int tmp = solve(n-(i*3), depth+1);

        ret += tmp;
    }

    return ret;

}

int main(){

    int n = 0;

    scanf("%d", &n);

    printf("%d", solve(n, 1));

    return 0;
}
