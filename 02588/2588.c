#include <stdio.h>

int main(){
     
    int a = 0, b = 0;

    scanf("%d %d", &a, &b);

    int temp = b;

    while(temp){
        printf("%d\n", a * (temp%10));
        temp /= 10;
    }

    printf("%d", a*b);

    return 0;
}
