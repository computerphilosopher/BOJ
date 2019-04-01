#include <stdio.h>


int split_sum(int n){


    int digit_sum = 0;

    int temp = n;

    while(temp != 0){

        digit_sum += (temp%10);
        temp /= 10;
    }

    return n + digit_sum;

}

int main(){

    int n = 0;

   scanf("%d", &n);

    int answer = 0;


    for(int i = 1; i<n; i++){
        if(split_sum(i)== n){
            answer = i;
            break;
        }
    }

    printf("%d", answer);

}
