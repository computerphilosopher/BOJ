#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int box[200][200][200];

class Point{
    public:
        int f, r, c, day;

        Point(int f, int r, int c, int day){
            this->f = f;
            this->r = r;
            this->c = c;
            this->day = day;
        }

};

void bfs(int h, int m, int n){

    queue <Point> q;

    for(int i=0; i<h; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<n; k++){
                if(box[i][j][k] == 1){
                    Point p(i, j, k, 0);
                    q.push(p);
                }
            }
        }
    }

    while(!q.empty()){
        Point here = q.front();
        q.pop();

        int f = here.f;
        int r = here.r;
        int c = here.c;
        int day = here.day;

        if(f+1 < h){
            if(!box[f+1][r][c]){
                Point up(f+1, r, c, day+1);
                box[f+1][r][c] = day+1;
                q.push(up);

            }
        }

        if(f > 0){
            if(!box[f-1][r][c]){
                Point down(f-1, r, c, day+1);
                box[f-1][r][c] = day+1;
                q.push(down);
            }
        }

        if(r+1 < m){
            if(!box[f][r+1][c]){
                Point front(f, r+1, c, day+1);
                box[f][r+1][c] = day+1;
                q.push(front);
            }
        }

        if(r > 0){
            if(!box[f][r-1][c]){
                Point back(f, r-1, c, day+1);
                box[f][r-1][c] = day+1;
                q.push(back);
            }
        }

        if(c+1 < n){
            if(!box[f][r][c+1]){
                Point right(f, r, c+1, day+1);
                box[f][r][c+1] = day+1;
                q.push(right);
            }
        }

        if(c > 0){
            if(!box[f][r][c-1]){
                Point left(f, r, c-1, day+1);
                box[f][r][c-1] = day+1;
                q.push(left);
            }
        }

    }
}


int solve(int h, int m, int n){

    int ret = 0;

    for(int i=0; i<h; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<n; k++){

                int here = box[i][j][k];

                if(!here){
                    return -1;
                }
                if(here > 1){
                    ret = max(ret,here);
                }
            }
        }
    }

    return ret;
}

int main(){

    int m = 0;
    int n = 0;
    int h = 0;

    scanf("%d %d %d", &n, &m, &h);

    for(int i=0; i<h; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<n; k++){
                scanf("%d", &box[i][j][k]);
            }
        }
    }

    bfs(h, m, n);
    printf("%d",solve(h, m, n));

    return 0;
}



