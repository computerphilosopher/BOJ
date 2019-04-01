#include <stdio.h>
 
 


long long solve(int A[], int size, int B, int C){

    long long answer = size;

    for(int i=0; i<size; i++){

        if(B >= A[i]){
            continue;
        }
        
        int temp = (A[i]-B) / C;
         
        if( (A[i]-B) %C){
            temp++;
        }

        answer += temp;
    }

    return answer;
}

int main(){

    int n = 0;
    scanf("%d", &n);

    int A[n];

    for(int i=0; i<n; i++){

        scanf("%d", &A[i]);
        
    }

    int b = 0;
    int c = 0;

    scanf("%d %d", &b, &c);

    printf("%lld", solve(A,n,b,c));
}
