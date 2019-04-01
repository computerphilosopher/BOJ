#include <stdio.h>

int forest[500][500];
int cache[500][500];

int n;
int max(int a, int b){
    if(a>b){
        return a;
    }
    return b;
}

int dp(int r, int c){
    
    int *ret = &cache[r][c];
     
    int *current = &forest[r][c];


    if(*ret){
        return *ret;
    }

    if(r > 0){

        int *up = &forest[r-1][c];

        if(*up > *current){
            *ret = max(*ret, dp(r-1, c));
        }
    }

    if(r+1 < n){
        int *down = &forest[r+1][c];

        if(*down > *current){
            *ret = max(*ret, dp(r+1, c));
        }
    }

    if(c > 0){

        int *left = &forest[r][c-1];

        if(*left > *current){
            *ret = max(*ret, dp(r, c-1));
        }
    }
     
    if(c+1 < n){

        int *right= &forest[r][c+1];

        if(*right > *current){
            *ret = max(*ret, dp(r, c+1));
        }
    }

    return *ret += 1;

}

int main(){

    scanf("%d", &n);

    for(int r=0; r<n; r++){
        for(int c=0; c<n; c++){
            scanf("%d", &forest[r][c]);
        }
    }

    int ans = -1;

    for(int r=0; r<n; r++){
        for(int c=0; c<n; c++){
            ans = max(ans, dp(r,c));
        }
    }

    printf("%d", ans);
}
