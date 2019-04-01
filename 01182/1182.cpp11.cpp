#include <stdio.h>
 
#include <vector>
#include <algorithm>

using namespace std;
 
vector <int> set;

int subset(const vector<int>& set, int i, int s){
     
    if(i >= set.size()){
        return 0;
    }
     
    if(set[i] == s){
        return 1 + subset(set, i+1, s-set[i]) + subset(set, i+1, s);
    }

    return subset(set, i+1, s - set[i]) + subset(set, i+1, s);
}
 
int main(){

    int n = 0;
    int s = 0;

    scanf("%d %d", &n, &s);


    for(int i=0; i<n; i++){
        int temp = 0;
        scanf("%d", &temp);
        set.push_back(temp);
    }

    printf("%d", subset(set, 0, s));

    return 0;
}
