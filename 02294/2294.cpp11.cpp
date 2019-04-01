#include <cstdio>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

vector<int> coins;

int cache[101][10001];

const int dp(const int i, const int k){
     
    if(i >= coins.size() || k < 0){
        return -1;
    }
     
    if(k == coins[i]){
        return 1;
    }

    int &ret = cache[i][k];

    if(ret != -100){
        return ret;
    }
     
    int ans = INT_MAX;
     
    const int solve[3] = {dp(i, k-coins[i]), dp(i+1, k), dp(i+1, k-coins[i])};
     
    for(int i=0; i<3; i++){
        if(solve[i] != -1){
            ans = min(ans, solve[i]);
        }
    }

    if(ans == INT_MAX){
        return ret = -1;
    }
    
    else if(ans == solve[1]){
        return ret = ans;
    }
     
    else{
        return ret = ans+1;
    }

}

int main(){
    int n = 0, k = 0;
    scanf("%d %d", &n, &k);

    for(int i=0; i<n; i++){
        int temp = 0;
        scanf("%d", &temp);
        coins.push_back(temp);
    }

    fill(&cache[0][0], &cache[100][10001], -100);

    printf("%d", dp(0, k));

    return 0;

}


