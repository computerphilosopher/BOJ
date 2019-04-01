#include <stdio.h>
#include <vector>

using namespace std;

vector<int> arr;

void dfs(vector<int> &picked, int here){

    if(picked.size() ==  6){

        for(auto num : picked){
            printf("%d ", num);
        }

        printf("\n");
        return;
    }

    int n = arr.size();

    for(int i=here+1; i<n; i++){
        picked.push_back(arr[i]);
        dfs(picked, i);
        picked.pop_back();
    }
}

int main(){

    int n = -1;

    while(1){
        scanf("%d", &n);

        if(!n){
            break;
        }

        arr = vector<int>(n, 0);

        for(int i=0; i<n; i++){
            scanf("%d", &arr[i]);
        }

        vector<int> picked;

        for(int i=0; n-i >= 6; i++){
            picked.push_back(arr[i]);
            dfs(picked, i);
            picked.pop_back();
        }
        printf("\n");
    }

    return 0;
}
