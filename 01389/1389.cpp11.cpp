#include <stdio.h>
#include <limits.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(const vector <vector <int> > &graph, vector<int> &dist, int start){

    vector <bool> discovered(graph.size());

    queue <int> q;

    discovered[start] = true;
    dist[start] = 0;

    q.push(start);

    while(!q.empty()){
        int here = q.front();
        q.pop();

        for(auto adj : graph[here]){
            if(!discovered[adj]){
                discovered[adj] = true;
                dist[adj] = dist[here] + 1;
                q.push(adj);
            }
        }
    }
}

int sum(const vector<int> &v){

    int ret = 0;

    for(auto e : v){
        ret += e;
    }

    return ret;
}

int solve(const vector<vector <int> > &graph){

    int ret = 1;
    int minValue = INT_MAX;

    int n = graph.size();

    for(int start=1; start<n; start++){
        vector <int> dist(n, 0);
        bfs(graph, dist, start);

        int s = sum(dist);
        if(s < minValue){
            minValue = s;
            ret = start;
        }
    }

    return ret;
}

int main(){

    int n = 0;
    int m = 0;

    scanf("%d %d", &n, &m);

    vector<vector <int> >graph(n+1);

    for(int i=0; i<m; i++){
        int u = 0;
        int v = 0;

        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    printf("%d", solve(graph));

    return 0;
}

