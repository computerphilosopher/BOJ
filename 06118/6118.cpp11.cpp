#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

vector<vector <int> > graph;

vector<int> bfs(const int start){

    queue<int> q;
    vector<bool> discovered(graph.size(), false);
    vector<int> dist(graph.size(), 0);
     
    q.push(start);
    discovered[start] = true;
    dist[start] = 0;

    while(!q.empty()){
        const int here = q.front();

        q.pop();

        for(auto there : graph[here]){
            if(!discovered[there]){
                discovered[there] = true;
                q.push(there); 
                dist[there] = dist[here]+1; 
            }
        }
    }
     
    return dist;
}
int main(){

    int n = 0;
    int m = 0;

    scanf("%d %d", &n, &m);

    graph.resize(n+1);
     
    for(int i=0; i<m; i++){
        int u = 0;
        int v = 0;
         
        scanf("%d %d", &u, &v);

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> dist = bfs(1);

    int max_idx = 0;

    for(int i=1; i<dist.size(); i++){
        if(dist[max_idx] < dist[i]){
            max_idx = i;
        }
    }

    int max_count = 0;

    for(int i=1; i<dist.size(); i++){
        if(dist[max_idx] == dist[i]){
            ++max_count;
        }
    }

    printf("%d %d %d", max_idx, dist[max_idx], max_count);

    return 0;
    
}


