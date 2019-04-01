#include <stdio.h>

int f(int p, int q){

    if(p % 2){
       if(p == q-1){
           return 1;
       } 
    }

    int np = ((p-1)/2)+1;
    int nq = ((q-1)/2)+1;

    return 1+f(np, nq);
}
 
int main(){

    int n = 0;
    int p = 0;
    int q = 0;

    scanf("%d %d %d", &n, &p, &q);

    int solution = (p < q) ? f(p, q) : f(q, p);

    printf("%d", solution);

    return 0;
}
