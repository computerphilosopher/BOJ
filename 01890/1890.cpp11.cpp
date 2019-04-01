#include <stdio.h>
#include <vector>

using namespace std;

int n;
vector<vector <int> > board;
vector<vector <long long> > cache;


long long solve(int r, int c){
    
    if(r == n-1 && c == n-1){
        return 1;
    }
    
    int step = board[r][c];

    long long &ret = cache[r][c];

    if(ret != -1){
        return ret;
    }

    ret = 0;

    if(r+step < n){
        ret += solve(r+step, c);
    }
    
    if(c+step < n){
        ret += solve(r, c+step);
    }

    return ret;
}
  
int main(){

    scanf("%d", &n);

    board = vector<vector <int> >(n, vector<int>(n,0));
    cache = vector<vector <long long> >(n, vector<long long>(n,-1));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &board[i][j]);
        }
    }

    printf("%lld", solve(0,0));

    return 0;
}
