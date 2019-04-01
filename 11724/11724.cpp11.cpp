#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector <int> > graph;
vector<bool> visited;

void dfs(int here){

    visited[here] = true;

    for(auto adj : graph[here]){
        if(!visited[adj]){
            dfs(adj);
        }
    }
}

int solve(int n){
    
    int ret = 0;

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            dfs(i);
            ret++;
        }
    }
    return ret;
}

int main(){

    int n = 0;
    int m = 0;

    scanf("%d %d", &n, &m);

    graph = vector<vector <int> > (n+1);
    visited = vector<bool>(n+1, false);

    for(int i=0; i<m; i++){
        int u = 0;
        int v = 0;

        scanf("%d %d", &u, &v);

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    printf("%d", solve(n));
}

