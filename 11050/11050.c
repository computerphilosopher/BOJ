#include <stdio.h>
 
long long f(int n, int k){
    if(n == k || k == 0){
        return 1;
    }
    return f(n-1, k-1) + f(n-1, k);
}
 
int main(){
     
    int n, k;

    scanf("%d %d", &n, &k);

    printf("%lld", f(n, k));

    return 0;
}
