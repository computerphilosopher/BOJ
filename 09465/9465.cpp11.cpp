#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > board;
vector< vector<int> > cache;

int dp(int r, int c){

    if(c == 0){
        return board[r][0];
    }

    int &ret = cache[r][c];

    if(ret != -1){
        return ret;
    }

    int row = (r+1)%2;

    return ret = max(dp(row, c-1), dp(row, c-2)) + board[r][c];
}

int solution(int n){
    return max(dp(0, n-1), dp(1, n-1));
}


int main(){

    int t = 0;
    cin.sync_with_stdio(false);

    cin >> t;

    for(int i=0; i<t; i++){
        int n = 0;
        cin >> n;

        board = vector< vector <int> >(2, vector<int>(n, 0));
        cache = vector< vector <int> >(2, vector<int>(n, -1));

        for(int c=0; c<n; c++){
            cin >> board[0][c];
        }

        for(int c=0; c<n; c++){
            cin >> board[1][c];
        }
        cout << solution(n) << "\n";
    }
}
