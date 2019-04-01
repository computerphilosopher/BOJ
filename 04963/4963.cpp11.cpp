#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int w;
int h;

vector<vector <int> > board;
vector<vector <bool> > visited;

void dfs(int r, int c);

int connected_component(){

    int ret = 0;
     
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(board[i][j] && !visited[i][j]){
                dfs(i, j);
                ret++;
            }
        }
    }

    return ret;

}

void dfs(const int r, const int c){

    visited[r][c] = true;


    if(r+1 < h){

        if(board[r+1][c] && !visited[r+1][c]){
            dfs(r+1, c);
        }

        if(c+1 < w){
            if(board[r+1][c+1] && !visited[r+1][c+1]){
                dfs(r+1, c+1);
            }
        }

        if(c > 0){
            if(board[r+1][c-1] && !visited[r+1][c-1]){
                dfs(r+1, c-1);
            }
        }
    }

    if(r > 0){

        if(board[r-1][c] && !visited[r-1][c]){
            dfs(r-1, c);
        }

        if(c+1 < w){
            if(board[r-1][c+1] && !visited[r-1][c+1]){
                dfs(r-1, c+1);
            }
        }

        if(c > 0){
            if(board[r-1][c-1] && !visited[r-1][c-1]){
                dfs(r-1, c-1);
            }
        }
    }

    if(c+1 < w){
        if(board[r][c+1] && !visited[r][c+1]){
            dfs(r, c+1);
        }

    }

    if(c > 0){
        if(board[r][c-1] && !visited[r][c-1]){
            dfs(r, c-1);
        }
    }

    return;
}

int main(){

    while(1){

        scanf("%d %d", &w, &h);

        if(!w && !h){
            break;
        }

        board = vector<vector <int> > (h, vector<int>(w, 0));
        visited = vector<vector <bool> > (h, vector<bool>(w,false));

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                scanf("%d", &board[i][j]);
            }
        }

        printf("%d\n", connected_component());

    }
    return 0;
}
