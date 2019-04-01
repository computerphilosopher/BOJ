#include <stdio.h>
 
int f(int stick, int x){

    int sum = stick;
    int shortest = stick;

    int count = 1;

    while(sum > x){

        int half = shortest/2;

        if(sum - half >= x){
            sum -= half;
            shortest = half;
        }

        else{
            shortest= half;
            count++;
        }
    }

    return count;
}
int main(){
    int n = 0;
    scanf("%d", &n);

    printf("%d", f(64, n));
}
