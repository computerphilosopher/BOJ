#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){

    int height[9] = {0};

    int sum = 0;

    for(int i=0; i<9; i++){
        scanf("%d", &height[i]);
        sum += height[i];
    }

    int exception1 = -1;
    int exception2 = -1;
    
    sort(height, height+9);

    for(int i=0; i<9; i++){
        for(int j=i+1; j<9; j++){
            
            if(sum - (height[i] + height[j]) == 100){
                exception1 = i;
                exception2 = j;
            }
        }
    }


    for(int i=0; i<9; i++){
        if(i != exception1 && i != exception2){
            printf("%d\n", height[i]);
        }
    }

    return 0;

}


