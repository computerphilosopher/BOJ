#include <stdio.h>
#include <algorithm>

using namespace std;

int minS(int A[], int B[], int n){

    sort(A, A+n);
    sort(B, B+n);

    int ret = 0;

    int Alow = 0;
    int Blow = 0;
    
    int Ahigh = n-1;
    int Bhigh = n-1;

    while((Ahigh >= Alow) && Bhigh >= Blow){
        if(A[Ahigh] <= B[Bhigh]){
            ret += A[Alow++] * B[Bhigh--];
        }
        else{
            ret += B[Blow++] * A[Ahigh--];
        }
    }

    return ret;

}

int main(){

    int n = 0;
    scanf("%d", &n);

    int A[n];
    int B[n];

    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }

    for(int i=0; i<n; i++){
        scanf("%d", &B[i]);
    }

    printf("%d", minS(A, B, n));

}
