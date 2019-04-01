#include <stdio.h>
#include <stdbool.h>

int distance(int n){
    return (n%10) - ((n/10)%10);

}
bool is_hansu(int n){

    int num = n;
    int d = distance(n);

    while(num >= 10){
         
        if(distance(num) != d){
            return false;
        }
        num /= 10;
    }

    return true;
}

int main(){

    int n = 0;
    scanf("%d", &n);

    int sum=0;


    for(int i=1; i<=n; i++){
        sum += is_hansu(i);
    }

    printf("%d",sum);

    return 0;
}

