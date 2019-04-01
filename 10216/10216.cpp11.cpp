#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;


class Point{
    public:
    int x, y, r;

    Point(int x, int y, int r){
        this->x = x;
        this->y = y;
        this->r = r;
    }
};

double dist(Point a, Point b){
    int xd = (b.x - a.x) * (b.x-a.x);
    int yd = (b.y - a.y) * (b.y-a.y);

    double sqd = xd + yd;

    return sqrt(sqd);
}

void dfs(const vector <Point> &v, vector<bool> &visited, int here){

    visited[here] = true;

    int r1 = v[here].r;

    for(int i=0; i<v.size(); i++){

        if(!visited[i] && here != i){

            int r2 = v[i].r; 

            double d = dist(v[here], v[i]);

            if(r1 + r2 >= d){
                dfs(v, visited, i);
            }
        }
    }
}

int solve(const vector<Point> &v){

    int n = v.size();
    vector<bool> visited(n, false);

    int ret = 0;

    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(v, visited, i);
            ret++;
        }
    }

    return ret;
}

int main(){

    int t = 0;
    scanf("%d", &t);

    for(int i=0; i<t; i++){
        int n = 0;
        scanf("%d", &n);

        vector<Point> v;

        for(int j=0; j<n; j++){
            int x, y, r;

            scanf("%d %d %d", &x, &y, &r);

            Point point(x, y, r);
            v.push_back(point);
        }

        printf("%d\n", solve(v));

    }

    return 0;
}