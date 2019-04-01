#include <stdio.h>
 
 
#include <stdlib.h>
#include <string.h>

int n;
int triangle[501][501];
int memo[501][501];

void tri_init(){
    for(int i=0; i<501; i++){
        memset(triangle[i], -1, sizeof(int)* 501);
    }
    for(int i=0; i<501; i++){
        memset(memo[i], -1, sizeof(int)* 501);
    }
}


int max(int a, int b){

    if(a > b){
        return a;
    }

    else{
        return b;
    }
}

int pathsum(int r, int c){

    
    if(r >= n-1){
        return triangle[r][c];
    }

    int *ref = &(memo[r][c]);

    if(*ref != -1){
        return *ref;
    }

    else{
        *ref = max(pathsum(r+1, c), pathsum(r+1, c+1)) + triangle[r][c];

        return *ref;
    }

}

int main(){

    tri_init();

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            scanf("%d", &triangle[i][j]);
        }
    }
    printf("%d", pathsum(0, 0));
}
