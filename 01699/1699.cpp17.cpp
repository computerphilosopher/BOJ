#include <bits/stdc++.h>

using namespace std;

enum{
INF =100000,
};
int cache[INF+1];

int min_squre_sum(const int n){

    if(n < 1){
        return n;
    }

    int &ret = cache[n];

    if(ret != -1){
        return ret;
    }

    ret = n;
    int i = 1;

    while(i*i <= n){
        if(i*i == n){
            return ret = 1;
        }

        ret = min(ret, min_squre_sum(n - (i*i))+1);
        i++;
    }
    return ret;
}

int main(){
    int n = 0;
    cin >> n;

    fill(&cache[0], &cache[100001], -1);

    cout << min_squre_sum(n);
   return 0;
}
