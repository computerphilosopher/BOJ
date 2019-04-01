#include <stdio.h>
#include <stdbool.h>

int main(){
     
    int n = 0;
    int l = 0;
    
    scanf("%d %d", &n, &l);

    int p = 0;

    while(true){

        if(l > 100){
            break;
        }
         
        int sum = (2*(l-1) + (l-2)*(l-1))/2;

        if((n-sum) % l == 0){
            p = (n-sum)/l;
            break;
        }
         
        l++;
    }

    if(l > 100 || p < 0){
        printf("-1");
    }

    else{
        for(int i=0; i<l; i++){
            printf("%d ", p+i);
        }
    }

    return 0;
}
