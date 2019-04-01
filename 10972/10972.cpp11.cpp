#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
 
int main(){
    int n = 0;
    scanf("%d", &n);

    vector<int> v;
     
    for(int i=0; i<n; i++){
        int temp = 0;
        scanf("%d", &temp);

        v.push_back(temp);
    }

    if(next_permutation(v.begin(), v.end())){
        for(auto num : v){
            printf("%d ", num);
        }
    }
    else{
        printf("-1");
    }

    return 0;
}

