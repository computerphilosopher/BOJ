#include <stdio.h>

void space(int n){
    for(int i=0; i<n; i++){
        printf(" ");
    }
}

int main(){

    int n = 0;
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        for(int j=0; j<i; j++){
            printf("*");
        }

        space((2*n)-(2*i));
        
        for(int j=0; j<i; j++){
            printf("*");
        }
        printf("\n");
    }

    for(int i=n-1; i>=1; i--){
        for(int j=0; j<i; j++){
            printf("*");
        }

        space((2*n)-(2*i));

        for(int j=0; j<i; j++){
            printf("*");
        }
        printf("\n");
    }

    return 0;

}
