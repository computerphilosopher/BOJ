#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <utility>

#define MAX_IDX 1000001

using namespace std;

int dist[MAX_IDX];
vector<int> parent;

int bfs(const int start, const int dest){

    queue<pair<int,int> > q;

    q.push(pair<int, int> (start, 0));

    int d = 0;

    dist[start] = 0;
    parent[start] = start;

    while(!q.empty()){
    
            pair<int, int> here = q.front();
    
            const int h = here.first;
            const int t = here.second;
             
            q.pop();

            if(here.first == dest){
                return t;
            }
             
            if(h*2 < MAX_IDX && dist[h*2] == -1)  {
                q.push(pair<int, int> (h*2, t+1));
                dist[h*2] = dist[h]+1;
                parent[h*2] = h;
            }

            if(h > 0 && dist[h-1] == -1)  {
                q.push(pair<int,int>(h-1, t+1));
                dist[h-1] = dist[h]+1;
                parent[h-1] = h;
            }

            if(h < MAX_IDX && dist[h+1] == -1)  {
                q.push(pair<int, int>(h+1, t+1));
                dist[h+1] = dist[h]+1;
                parent[h+1] = h;
            }
    }

    return -1;

}

vector<int> shortestPath(int k, const vector<int> &parent){

    vector<int> path(1, k);

    while(parent[k] != k){
        k = parent[k];
        path.push_back(k);
    }

    reverse(path.begin(), path.end());
    return path;
}

int main(){

    int n=0;
    int k=0;

    cin >> n >> k;

    fill(&dist[0], &dist[MAX_IDX], -1);
    parent = vector<int>(MAX_IDX, -1);

    cout << bfs(n, k) << "\n";

    vector<int> path = shortestPath(k, parent);

    for(auto v : path){
        cout << v << " ";
    }

    return 0;
}
