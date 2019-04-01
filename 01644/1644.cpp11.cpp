#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void erato(vector<bool> &is_prime){

    is_prime[0] = false;
    is_prime[1] = false;
     
    for(int i=2; i<is_prime.size(); i++){
        if(is_prime[i]){
            for(int j=2; i*j<is_prime.size(); j++){
                is_prime[i*j] = false;
            }
        }
    }
}

int two_pointer(vector <int>& prime, int n){
     
    if(n == 1){
        return 0;
    }
    int s = 0;
    int e = 0;

    int sum = prime[0];

    int ret = 0;
     
    while(s <= e && e < prime.size()){
         
        if(sum > n){
            sum -= prime[s++];
        }
        else if(sum == n){
            ret++;
            sum -= prime[s++];
        }

        else { 
            sum += prime[++e];
        }
    }

    return ret;
}


int main(){

    int n = 0;
    scanf("%d", &n);

    vector<bool> is_prime(n*2, true);

    erato(is_prime);

    vector<int> prime;

    for(int i=2; i<is_prime.size(); i++){
        if(is_prime[i]){
            prime.push_back(i);
        }
    }

    printf("%d", two_pointer(prime, n));

    return 0;

}
