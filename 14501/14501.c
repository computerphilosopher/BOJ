#include <stdio.h>
#include <stdlib.h>

int n;

int *price;
int *time;

int max(int a, int b){
    return (a>b) ? a: b;
}

int backtrack(int day, int remain){

    if(day > n){
        return 0;
    }

    if(remain > 0){
        return backtrack(day+1, remain-1);
    }

    else if(remain == 0){

        int yes = 0;
        int no = 0;

        if(day+time[day]-1 <= n){
            yes = price[day] + backtrack(day+1, time[day]-1);
        }

        no = backtrack(day+1, 0);

        return max(yes, no);
    }

    else{
        return 0;
    }
}

int main(){

    scanf("%d", &n);

    time = (int*)calloc(n+1, sizeof(int));
    price = (int*)calloc(n+1, sizeof(int));

    for(int i=1; i<=n; i++){
        int t = 0;
        int p = 0;

        scanf("%d %d", &t, &p);

        time[i] = t;
        price[i] = p;
    }

    printf("%d", backtrack(1, 0));
    
    return 0;
}
