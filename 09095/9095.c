#include <stdio.h>
 
int comb(int n){

    if(n < 0 ){
        return 0;
    }
    if(n == 0){
        return 1;
    }

    return comb(n-1) + comb(n-2) + comb(n-3);
}

int main(){

    int t = 0;

    scanf("%d", &t);

    for(int i=0; i<t; i++){

        int n = 0;
        scanf("%d", &n);
        printf("%d\n", comb(n));
    }

}