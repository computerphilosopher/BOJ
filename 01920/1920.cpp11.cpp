#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


bool binSearch(const vector<int> &v, const int left, const int right, const int target){

    if(left > right){
        return false;
    }

    const int mid = (left+right)/2;

    if(v[mid] == target){
        return true;
    }

    else if(v[mid] > target){
        return binSearch(v, left, mid-1, target);
    }

    else{
        return binSearch(v, mid+1, right, target);
    }

    return false;
}
int main(){
    int n = 0;
    scanf("%d", &n);

    vector<int> v(n, 0);

    for(int i=0; i<n; i++){
       scanf("%d", &v[i]); 
    }
    
    sort(v.begin(), v.end());
    int m = 0;
    scanf("%d", &m);

    for(int i=0; i<m; i++){
        int target = 0;
        scanf("%d", &target);
        printf("%d\n", binSearch(v, 0, v.size()-1, target));
    }

    return 0;
}