#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector <int> > board;

class Point{
    public:
        int r, c, day;

        Point(int r, int c, int day){
            this->r = r;
            this->c = c;
            this->day = day;
        }
};

int bfs(){

    int m = board.size();
    int n = board[0].size();

    vector<vector <bool> > discovered = vector<vector <bool> >(m, vector<bool>(n, false));

    queue<Point> q;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == 1){
                discovered[i][j] = true;
                Point point(i, j, 0);
                q.push(point);
            }
        }
    }

    while(!q.empty()){

        Point point = q.front();
        q.pop();

        int r = point.r;
        int c = point.c;
        int day = point.day;

        if(r+1 < m && !board[r+1][c]){
            if(!discovered[r+1][c]){
                discovered[r+1][c] = true;

                board[r+1][c] = day+1;

                Point down(r+1, c, day+1);
                q.push(down);
            }
        }

        if(r > 0 && !board[r-1][c]){

            if(!discovered[r-1][c]){

                discovered[r-1][c] = true;
                board[r-1][c] = day+1;

                Point up(r-1, c, day+1);
                q.push(up);
            }

        }

        if(c+1 < n && !board[r][c+1]){
            if(!discovered[r][c+1]){
                discovered[r][c+1] = true;

                board[r][c+1] = day+1;

                Point right(r, c+1, day+1);
                q.push(right);
            }
        }

        if(c > 0 && !board[r][c-1]){
            if(!discovered[r][c-1]){

                discovered[r][c-1] = true;
                board[r][c-1] = day+1;

                Point left(r, c-1, day+1);
                q.push(left);
            }
        }
    }

    int ret = 0;

    for(auto row : board){
        for(auto point : row){

            if(!point){
                return -1;
            }
            if(point > 1){
                ret = max(point, ret);
            }
        }
    }

    return ret;
}

int main(){

    int m = 0;
    int n = 0;

    scanf("%d %d", &n, &m);

    board = vector<vector<int> >(m, vector<int>(n,0));

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &board[i][j]);
        }
    }

    printf("%d", bfs());

    return 0;
}
