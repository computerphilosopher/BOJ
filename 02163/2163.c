#include <stdio.h>

int solve(int n, int m){
    return (n*m)-1;
}
int main(){

    int n = 0;
    int m = 0;

    scanf("%d %d", &n, &m);

    printf("%d", solve(n,m));

}
