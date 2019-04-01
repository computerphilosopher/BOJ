#include <stdio.h>

int check[100000];

int d(int n){

    int num = n;
    int sum = 0;

    while(num){
        int temp= num%10;

        sum += temp;
        num /= 10;
    }

    return sum+n;
}

int main(){

    int res = 0;
    int n = 1;


    while(n <= 10000){
        res = d(n++);
        check[res] = check[res] + 1;
    }

    for(int i=1; i<=10000; i++){
        if(!check[i]){
            printf("%d\n", i);
        }
    }

    return 0;

}
