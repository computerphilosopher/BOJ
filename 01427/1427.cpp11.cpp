#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solve(const int n){

    int k = n;
    vector<int> v;

    while(k){
        v.push_back(k%10);
        k /= 10;
    }

    sort(v.begin(), v.end(), less<int>());

    int ret = 0;
    int ex = 1;

    for(auto num : v){
        ret += num*ex;
        ex *= 10;
    }

    return ret;

}

int main(){
    int n = 0;
    scanf("%d", &n);

    printf("%d",solve(n));

    return 0;
}
