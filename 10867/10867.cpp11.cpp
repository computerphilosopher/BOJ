#include <stdio.h>
#include <algorithm>
#include <vector>

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

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(auto num : v){
        printf("%d ", num);
    }

    return 0;
}
