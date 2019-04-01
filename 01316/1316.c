#include <stdio.h>
#include <stdbool.h>

bool is_group(char str[]){

    int count[128] = {0};

    int i = 0;

    while(str[i] != '\0'){
        
        char cur = str[i];

        if(count[cur]){
            if(str[i-1] != cur){
                return false;
            }
        }

        count[cur]++;
        i++;
    }

    return true;
}

int main(){

    int n = 0;

    scanf("%d", &n);

    int ans = 0;

    for(int i=0; i<n; i++){
        char str[101];
        scanf("%s", str);

        ans += is_group(str);
    }

    printf("%d", ans);
}
