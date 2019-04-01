#include <stdio.h>
 
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LIMIT 123457

bool *prime;

void fill_prime(){

    prime[1] = false;

    for(int i=2; i<=3*LIMIT; i++){
        if(prime[i]){
            for(int j=2; i*j <= 3*LIMIT; j++){
                prime[i*j] = false;
            }
        }
    }
}

int solve(int n){

    int ret = 0;

    for(int i=n+1; i<=(2*n); i++){
        if(prime[i]){
            ret++;
        }
    }
    return ret;
}

int main(){

    prime = (bool*)malloc(LIMIT*3*sizeof(bool));
    memset(prime, true, LIMIT*3*sizeof(bool));

    fill_prime();

    while(1){

        int n = 0;
        scanf("%d", &n);

        if(n == 0){
            break;
        }

        printf("%d\n",solve(n));
    }

    free(prime);

    return 0;
}

