#include <stdio.h>


int range_sum(int s, int e, int psum[]){
    if(s == 0){
        return psum[e];
    }
    return psum[e] - psum[s-1];
}
 
int main(){
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);

    int arr[n];
    int psum[n];
     
    int sum = 0;
     
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];

        psum[i] = sum;
    }

    int ans = 0;
     
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){

            int temp = range_sum(i, j, psum);

            if(temp == m){
                ans++;
            }
        }
    }

    printf("%d", ans);

    return 0;
}
