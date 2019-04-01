#include <stdio.h>

int main(){

    int E = 0, S = 0, M = 0;

    scanf("%d %d %d", &E, &S, &M);

    int e = 1, s = 1, m = 1;
    int year = 1;

    while(e != E || s != S || m != M){
         
        e = (e+1)%16;
        e = e == 0 ? 1: e;
         
        s = (s+1)%29;
        s = s == 0 ? 1: s;
         
        m = (m+1)%20;
        m = m == 0 ? 1: m;

        ++year;
    }

    printf("%d", year);

    return 0;

}
