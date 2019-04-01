#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

stack<int> sorted;
vector <bool> visited;

vector <vector<int> > graph;

void dfs(int here){

    visited[here] = true;

    for(int i=0; i<graph[here].size(); i++){
        int node = graph[here][i];
        if(!visited[node]){
            dfs(node);
        }
    }

    sorted.push(here);
}

void search(){

    for(int i=1; i<graph.size(); i++){
        if(!visited[i]){
            dfs(i);
        }
    }
}

void print(){
    while(!sorted.empty()){
        int node = sorted.top();
        sorted.pop();

        cout << node << " ";
    }
}

int main(){
    int n = 0;
    int m = 0;

    cin >> n >> m;

    graph = vector <vector <int> > (n+1);
    visited = vector<bool>(n+1, false);

    for(int i=0; i<m; i++){
        int a = 0;
        int b = 0;

        cin >> a >> b;
        graph[a].push_back(b);
    }

    search();
    print();
    return 0;
}