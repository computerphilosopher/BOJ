#include <cstdio>
#include <algorithm>

using namespace std;

int solve(int A[], int n){

    sort(A, A+n);

    int ret = 0;

    for(int i=0; i<n; i++){
        ret += A[i];
        for(int j=0; j<i; j++){
            ret += A[j];
        }
    }

    return ret;
}

int main(){

    int n = 0;

    scanf("%d", &n);

    int A[n];

    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }

    printf("%d", solve(A, n));
}
