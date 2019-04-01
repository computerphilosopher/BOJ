#include <stdio.h>

int max(int a, int b){
    return a>b ? a:b;
}

int main(){

    for(int t=0; t<3; t++){
        char input[9] = {0};
        scanf("%s", input);
         
        int count = 1;
        int ans = 0;
         
        for(int i=1; i<8; i++){
            count = (input[i] == input[i-1]) ? count+1 : 1;
            ans = max(ans, count);
        }
        printf("%d\n", ans);
    }

    return 0;

}
