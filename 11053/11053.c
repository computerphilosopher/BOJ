#include <stdio.h>

int cache[1000];

int LIS(int A[], int n){

    int max = 0;

    for(int i=0; i<n; i++){
        cache[i] = 1;
        for(int j=0; j<i; j++){
            if(A[j] < A[i]){
                if(cache[i] < cache[j]+1){
                    cache[i] = cache[j]+1;
                }
            }
        }

        if(max < cache[i]){
            max = cache[i];
        }
    }

    return max;

}
int main(){

    int n = 0;
    scanf("%d", &n);

    int A[n];


    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }

    printf("%d", LIS(A, n));

}
