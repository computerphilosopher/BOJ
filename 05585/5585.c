#include <stdio.h>

int dfs(int k){
    
    if(k <= 0){
        return 0;
    }

    if(k >= 500){
        return 1+dfs(k-500);
    }

    else if(k >= 100){
        return 1+dfs(k-100);
    }

    else if(k >= 50){
        return 1+dfs(k-50);
    }
    
    else if(k >= 10){
        return 1+dfs(k-10);
    }
    
    else if(k >= 5){
        return 1+dfs(k-5);
    }

    else{
        return 1+dfs(k-1);
    }

}
int main(){

    int k = 0;
    scanf("%d", &k);

    printf("%d",dfs(1000-k));
}
