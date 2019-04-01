#include <stdio.h>

int gcd(const int big, const int small){

    if(big % small == 0){
        return small;
    }

    const int r = big % small;

    return gcd(small, r);
}

long long solve(const int arr[], const int n){

    long long ret = 0;
     
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            ret += gcd(arr[i], arr[j]);
        }
    }

    return ret;
}

int main(){

    int t = 0;
    scanf("%d", &t);

    for(int tc = 0; tc<t; tc++){
         
        int n = 0;
        scanf("%d", &n);

        int arr[n];

        for(int i=0; i<n; i++){
            scanf("%d", &arr[i]);
        }

        printf("%lld\n", solve(arr, n));
    }

    return 0;
}
