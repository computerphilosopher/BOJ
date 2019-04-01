#include <stdio.h>
 

int main(){
    int n = 0;
    int m = 0;

    scanf("%d %d", &n, &m);

    int A[n];
    int B[m];
    int C[n+m];

    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    
    for(int i=0; i<m; i++){
        scanf("%d", &B[i]);
    }

    int a = 0;
    int b = 0;
    int c = 0;

    while(c < n+m){

        if(a < n && b < m){
            if(A[a] <= B[b]){
                C[c++] = A[a++];
            }
            else{
                C[c++] = B[b++];
            }
        }

        else if(a >= n){
            for(int i = b; i <= m; i++){
                C[c++] = B[i];
            }
            break;
        }

        else{
            for(int i = a; i <= n; i++){
                C[c++] = A[i];
            }
            break;
        }
    }

    for(int i = 0; i<n+m; i++){
        printf("%d ", C[i]);
    }

    return 0;
}
