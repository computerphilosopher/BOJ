#include <cstdio>
 
#include <vector>
#include <queue>
#include <limits.h>
 

using namespace std;

#define MAX_IDX 100001

class Point{

    public:
    int x, count;

    Point(int x, int count){
        this->x = x;
        this->count = count;
    }
    
};

typedef struct Solution{
    int distance, count;
}Solution;

bool discoverd[MAX_IDX];


Solution bfs(const Point start, const int dest){

    queue<Point> q;

    q.push(start);

    Solution s = {INT_MAX, 0};

    while(!q.empty()){

        Point here = q.front();
        q.pop();

        int x = here.x;
        int count = here.count;

        discoverd[x] = true;

        if(x == dest){
            if(s.distance >= count){
                s.distance = count;
                ++s.count;
            }
        }

        if(x+1 <= MAX_IDX && !discoverd[x+1]){
            Point temp(x+1, count+1);
            q.push(temp);
        }

        if(x>0 && !discoverd[x-1]){
            Point temp(x-1, count+1);
            q.push(temp);
        }

        if(x*2 <= MAX_IDX && !discoverd[x*2]){
            Point temp(x*2, count+1);
            q.push(temp);
        }
    }

    return s;

}

int main(){
    int n = 0;
    int k = 0;

    scanf("%d %d", &n, &k);

    Point start(n, 0);

    Solution s = bfs(start, k);

    printf("%d\n%d", s.distance, s.count);

}
