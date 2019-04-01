#include <stdio.h>
 
#include <stdbool.h>

int rows, cols;

int dfs(int r, int c, bool board[50][50], bool visited[50][50]){

    visited[r][c] = true;

    if(board[r+1][c] && !visited[r+1][c]){
        if(r < rows-1){
            dfs(r+1, c, board, visited);
        }
    }

    if(board[r-1][c] && !visited[r-1][c]){
        if(r > 0){
            dfs(r-1, c, board, visited);
        }
    }

    if(board[r][c+1] && !visited[r][c+1]){
        if(c < cols-1){
            dfs(r, c+1, board, visited);
        }
    }

    if(board[r][c-1] && !visited[r][c-1]){
        if(c > 0){
            dfs(r, c-1, board, visited);
        }
    }

    board[r][c] = false;
    return 1;
}
int main(){

    int t = 0;

    scanf("%d", &t);

    for(int i=0; i<t; i++){

        int k = 0;

        scanf("%d %d %d", &cols, &rows, &k);

        bool board[50][50] = {0};

        for(int j=0; j<k; j++){

            int r =0;
            int c =0;

            scanf("%d %d", &c, &r);

            board[r][c] = true;
        }

        int ans = 0;

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){

                if(board[r][c]){
                    bool visited[50][50] = {false};
                    dfs(r,c, board, visited);
                    ans++;
                }
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}

