#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int board[16];

int n;

bool is_promising(const int row){

    if(row == -1){
        return true;
    }
    
    for(int i=0; i<row; i++){

        if(board[i] == board[row]){
            return false;
        }

        else if((row - i) == abs(board[row] - board[i])){
            return false;
        }
    }

    return true;
}

int nqueen(const int row){

    if(!is_promising(row)){
        return 0;
    }

    if(row == n-1){
        return 1;
    }

    int ret = 0;

    for(int i=0; i<n; i++){

        board[row+1] = i; 

        int temp = nqueen(row+1);

        ret += temp;

    }

    return ret;
}


int main(){

    scanf("%d", &n);
    printf("%d", nqueen(-1));
}
