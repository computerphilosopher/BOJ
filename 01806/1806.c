#include <stdio.h>
#include <limits.h>

int min(int a, int b){
    return a<b ? a:b;
}
 
int main(){
    int n = 0, s = 0;
    scanf("%d %d", &n, &s);

    int arr[n];

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int left = 0,  right= 0;
    int minlen = INT_MAX;

    int sum = arr[0];
     
    while(left <= right && right < n){

        if(sum >= s){
            minlen = min(minlen, right-left+1);
            sum -= arr[left++];
        }
         
        else{
            sum += arr[++right];
        }
    }

    printf("%d", minlen != INT_MAX ? minlen : 0);

    return 0;
}
