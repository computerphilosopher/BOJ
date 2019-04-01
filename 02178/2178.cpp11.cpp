#include <iostream>
 
 
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

vector< vector<int> > board;
vector< vector<bool> > discovered;

class Point{

    public:

    int r, c, count;

    Point(int r, int c){
        this->r = r;
        this->c = c;
        count = 1;
    }
};

int bfs(const Point start, const Point dest){

    queue<Point> q;

    q.push(start);

    int n = dest.r;
    int m = dest.c;

    while(!q.empty()){

        Point here = q.front();
        q.pop();

        int r = here.r;
        int c = here.c;

        if(r == n-1 &&  c == m-1){
            return here.count;
        }

        if(r+1 < n){
            if(board[r+1][c] && !discovered[r+1][c]){

                Point temp(r+1, c);

                temp.count = here.count+1;

                discovered[r+1][c] = true;

                q.push(temp);
            }
        }

        if(r > 0){
            if(board[r-1][c] && !discovered[r-1][c]){
                Point temp(r-1, c);
                temp.count = here.count+1;

                discovered[r-1][c] = true;
                q.push(temp);
            }
        }

        if(c+1 < m){
            if(board[r][c+1] && !discovered[r][c+1]){
                Point temp(r, c+1);
                temp.count = here.count+1;

                discovered[r][c+1] = true;
                q.push(temp);
            }
        }
        if(c > 0){
            if(board[r][c-1] && !discovered[r][c-1]){
                Point temp(r, c-1);
                temp.count = here.count+1;

                discovered[r][c-1] = true;
                q.push(temp);
            }
        }

    }

    return -1;

}

int main(){


    int n, m;

    cin >> n >> m;

    board = vector< vector<int> > (n, vector<int> (m, 0)); 
    discovered = vector< vector<bool> > (n, vector<bool> (m, false)); 

    for(int i=0; i<n; i++){

        string input;

        cin >> input;

        for(int j = 0; j<input.length(); j++){
            if(input[j] == '1'){
                board[i][j] = 1;
            }
            else{
                board[i][j] = 0;
            }
        }
        
    }


    Point start(0, 0);
    Point dest(n, m);

    cout << bfs(start, dest);

    return 0;

}




