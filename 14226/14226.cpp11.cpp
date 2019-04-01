#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>

using namespace std;
 
int bfs(const int dest){
     
    queue<pair <int, int> > q;

    vector< vector<int> > dist(10001, vector<int>(10001, numeric_limits<int>::max()));


    dist[0][1] = 0;
     
    q.push(make_pair(0, 1));
     
    while(!q.empty()){
         
        const pair<int, int> here = q.front();
        q.pop();

        const int clipboard = here.first;
        const int monitor = here.second;

        
        int d = dist[clipboard][monitor];

        if(monitor == dest){
            return d;
        }

        if(d+1 < dist[monitor][monitor]){
            dist[monitor][monitor] = d+1;
            q.push(make_pair(monitor, monitor));
        }

        if(d+1 < dist[clipboard][clipboard + monitor]){
            dist[clipboard][clipboard + monitor] = d+1;
            q.push(make_pair(clipboard, clipboard + monitor));
        }

        if(d+1 < dist[clipboard][monitor-1]){
            dist[clipboard][monitor-1] = d+1;
            q.push(make_pair(clipboard, monitor-1));
        }
    }
     
    return -1;
}
 
int main(){
     
    int s = 0;
    scanf("%d", &s);

    printf("%d", bfs(s));
}

 
