#include <stdio.h>
#include <string.h>


char itoc(const int n){
     
    if(n < 10){
        return n + '0';
    }

    return n - 10 + 'A'; 

}
 
void solve(const int n, const int digit){
     
    char ans[10000] = {0};

    int i = 0;

    int num = n;
     
    while(num){
        ans[i++] = itoc(num % digit);
        num /= digit;
    }

    const int len = strlen(ans);

    for(int i = len-1; i>=0; i--){
        printf("%c", ans[i]);
    }
    
    return;
}
 
int main(){
     
    int n = 0;
    scanf("%d", &n);

    int b = 0;
    scanf("%d", &b);

    solve(n, b);

    return 0;
}

