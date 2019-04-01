#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool broked[10];
 
const int limit = 2000000;
const int start = 100;
 
int min(const int a, const int b){
    return a < b ? a : b;
}

const bool is_broken(const int channel){

    int n = channel;

    if(n == 0){
        return broked[0];
    }

    while(n){
         
        int temp = n % 10;
         
        if(broked[temp]){
            return true;
        }

        n /= 10;
    }

    return false;
}

const int digit(const int n){
     
    int num = n;
    int ret = 0;
     
    if(num == 0){
        return 1;
    }
     
    while(num){
        num /= 10;
        ++ret;
    }

    return ret;
     
}

const int search(const int dest){

    int dist = abs(dest - start);

    int first_channel = 100;

    for(int ch=0; ch<limit; ch++){

        int temp = abs(dest - ch);
         
        if(!is_broken(ch)){
            if(dist > temp){
                dist = temp;
                first_channel = ch;
            }
        }
    }

    return min(abs(dest- start), dist + digit(first_channel));
     
}

int main(){
    int dest = 0;

    scanf("%d", &dest);

    int k = 0;

    scanf("%d", &k);

    for(int i=0; i<k; i++){
        int temp = 0;
        scanf("%d", &temp);

        broked[temp] = true;
    }

    printf("%d", search(dest));
    return 0;
}
