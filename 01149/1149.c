#include <stdio.h>
#include <limits.h>
#include <stdbool.h>


enum color{
    RED,
    GREEN,
    BLUE,
    COLOR_COUNT
};

int house[1001][3];
int cache[1001][3];

int min(int arr[], int n){

    int min = INT_MAX;
    
    for(int i=0; i<n; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }

    return min;
}


int dp(const int n, const int color){

    if(n == 0){
        return 0;
    }

    if(n == 1){
        return house[n][color];
    }

    int *ret = &cache[n][color];

    if(*ret){
        return *ret;
    }

    const int first = (color+1)%COLOR_COUNT;
    const int second = (color+2)%COLOR_COUNT;
    
    int arr[2] = {dp(n-1,first), dp(n-1,second)};
    
    return *ret = min(arr,2) + house[n][color];

}

int main(){

    int n = 0;
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        for(int j=0; j<COLOR_COUNT; j++){
            scanf ("%d", &house[i][j]);
        }
    }

    int arr[3] = {dp(n, RED), dp(n, GREEN), dp(n, BLUE)};

    printf("%d", min(arr,3));
}
