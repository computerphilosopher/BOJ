#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
 

int get_sum(const vector<int> &v){
     
    int ret = 0;
    int n = v.size();
     
    for(int i=0; i<n-1; i++){
        ret += abs(v[i] - v[i+1]);
    }
     
    return ret;
}
int main(){
     
    int n = 0;
    scanf("%d", &n);

    vector<int> v;

    for(int i=0; i<n; i++){
        int temp = 0;
        scanf("%d", &temp);

        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    int ans = -101;

    do{
        ans = max(ans, get_sum(v));
    }while(next_permutation(v.begin(), v.end()));

    printf("%d", ans);

    return 0;
}
