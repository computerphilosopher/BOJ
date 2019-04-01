#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector <vector <int> > graph;
vector <int> cost;

vector<int> cache;

int dp(int n){

    if(graph[n].empty()){
        return cost[n];
    }

    int &ret = cache[n];

    if(ret != -1){
        return ret;
    }

    int s = 0;

    for(auto parent : graph[n]){
        s = max(s, dp(parent));
    }

    return ret = cost[n] + s;
}

int main(){
    int n = 0;
    cin.sync_with_stdio(false);

    cin >> n;

    graph = vector<vector <int> >(n+1);
    cost = vector<int>(n+1);
    cache = vector<int>(n+1, -1);

    int node = 1;

    while(node <= n){
        int c = 0;
        cin >> c;

        cost[node] = c;

        int parent = 0;

        while(parent != -1){
            cin >> parent;

            if(parent != -1){
                graph[node].push_back(parent);
            }
        }

        node++;
    }

    for(int i=1; i<=n; i++){
        cout << dp(i) << "\n";
    }

    return 0;
}
