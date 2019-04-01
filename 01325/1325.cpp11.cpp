#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector < vector<int> > graph;

class solution{

    public:
        int n, count;

        solution(int n, int count){
            this->n = n;
            this->count = count;
        }
};


int dfs(const int here, vector<bool> &visited){

    visited[here] = true;

    int ans = 0;

    for(int i=0; i<graph[here].size(); i++){

        int there = graph[here][i];

        if(!visited[there]){
            ans += dfs(there, visited);
        }
    }

    return 1+ans;
}


bool great(solution s1, solution s2){
    return s1.count > s2.count;
}

int main(){
    
    int n = 0;
    int m = 0;

    cin.sync_with_stdio(false);
    cin >> n >> m;

    graph = vector< vector <int> >(n+1);

    for(int i=0; i<m; i++){

        int u = 0;
        int v = 0;

        cin >> v >> u;

        graph[u].push_back(v);
    }

    vector <solution> result;
    
    for(int i=1; i<=n; i++){
        vector<bool> visited(n+1, false);

        int temp = dfs(i, visited);

        solution s(i, temp);

        result.push_back(s);
    }

    sort(result.begin(), result.end(), great);

    /*
    for(int i=0; i<result.size(); i++){
        cout << result[i].n << "," << result[i].count <<endl;
    }
    */

    int max = result[0].count;

    vector <int> print;

    for(int i=0; i<result.size(); i++){
        if(result[i].count >= max){
            print.push_back(result[i].n);
        }
        else{
            break;
        }
    }

    sort(print.begin(), print.end());

    for(int i=0; i<print.size(); i++){
        cout << print[i] << " ";
    }

    return 0;
}
