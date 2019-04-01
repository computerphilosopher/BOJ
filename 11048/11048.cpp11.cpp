#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int cache[1001][1001];

int n, m;

vector < vector<int> > board;


int dp(int r, int c){

    if(r == 1 && c == 1){
        return board[1][1];
    }

    int &ret = cache[r][c];

    if(ret != -1){
        return ret;
    }

    int up = -1;
    int left = -1;
    int diagonal= -1;

    if(r > 0){
        up = dp(r-1, c);
    }
    
    if(c > 0){
        left = dp(r, c-1);
    }

    if(r>0 && c>0){
        diagonal = dp(r-1, c-1);
    }

    int arr[3] = {up, left, diagonal};

    return ret = *max_element(arr, arr+3) + board[r][c];

}


int main(){

    n = 0;
    m = 0;

    scanf("%d %d", &n, &m);

    board = vector < vector <int> > (n+1, vector<int>(m+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &board[i][j]);
        }
    }

    fill(&cache[0][0], &cache[1000][1001], -1);

    printf("%d", dp(n, m));

    return 0;

}

