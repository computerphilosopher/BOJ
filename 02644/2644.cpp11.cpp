#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector <vector <bool> > graph;
vector <int> dist;

int n;

void bfs(int start){

    queue<int> q;
    vector <bool > discovered(n+1, false);

    discovered[start] = true;

    dist[start] = 0;

    q.push(start);

    while(!q.empty()){
        int here = q.front();
        q.pop();

        for(int i=1; i<=n; i++){
            if(graph[here][i]){
                if(!discovered[i]){
                    discovered[i] =true;
                    q.push(i);
                    
                    dist[i] = dist[here] + 1;
                }
            }
        }

    }
    
}

int main(){

    int m = 0;

    int start = 0;
    int end = 0;

    cin.sync_with_stdio(false);

    cin >> n >> start >> end >> m;

    graph = vector<vector <bool> >(n+1, vector<bool>(n+1, false));

    dist = vector<int> (n+1, -1);

    for(int i=0; i<m; i++){
        int a = 0;
        int b = 0;

        cin >> a >> b;

        graph[a][b] = true;
        graph[b][a] = true;

    }

    bfs(start);

    cout << dist[end];
}
