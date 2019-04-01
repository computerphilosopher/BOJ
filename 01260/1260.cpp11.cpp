#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector< vector <bool> > graph;
vector <bool> visited;
vector <bool>  discovered;


void dfs(int here){

    visited[here] = true;
    cout << here << " ";

    for(int i=1; i<=visited.size()-1; i++){
        if(graph[here][i] && !visited[i]){
            dfs(i);
        }
    }

    return;
}

int bfs(int start){

    queue <int> q;
    
    q.push(start);

    discovered[start] = true;

    while(!q.empty()){

        int t = q.front();
        cout << t << " ";

        q.pop();

        for(int i=1; i<=discovered.size()-1; i++){
            if(graph[t][i] && !discovered[i]){
                discovered[i] = true;
                q.push(i);
            }
        }
    }
}

int main(){

    int n, m = 0;
    int v = 0;

    cin.sync_with_stdio(false);
    cin >> n >> m >> v;
    
    graph = vector <vector<bool> >(n+1, vector<bool>(n+1,false));
    visited = vector<bool>(n+1, false);
    discovered = vector<bool>(n+1, false);

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;

        graph[u][v] = true;
        graph[v][u] = true;
    }

    dfs(v);
    cout << endl;
    bfs(v);
     
    return 0;
}
