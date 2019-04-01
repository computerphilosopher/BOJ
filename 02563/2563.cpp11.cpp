#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

class Board{
    private:
        bool board[101][101];
        
    public:
        Board(){
            fill(&board[0][0], &board[100][101], false);
        }

        void fill_area(int sx, int sy){
            for(int i=sy; i<sy+10; i++){
                for(int j=sx; j<sx+10; j++){
                    board[i][j] = true;
                }
            }
        }

        int get_area(){
            int ret = 0;
            for(int i=0; i<=100; i++){
                for(int j=0; j<=100; j++){
                    ret += board[i][j];
                }
            }
            return ret;
        }

};

int main(){
    int n = 0;
    scanf("%d", &n);

    Board board;

    for(int i=0; i<n; i++){
        int sx = 0;
        int sy = 0;

        scanf("%d %d", &sx, &sy);

        board.fill_area(sx, sy);
    }

    printf("%d",board.get_area());

    return 0;
}
