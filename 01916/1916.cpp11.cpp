#include <cstdio>
#include <queue>
#include <vector>
#include <limits>
#include <functional>

using namespace std;
vector<vector <pair<int,int> > > graph; 

const int INF = numeric_limits<int>::max();

vector<int> shortest_path(int start){

    int n = graph.size();
    vector<int> dist(n, INF);

    priority_queue<pair<int, int>, vector<pair <int, int> >, greater<pair <int, int> > > pq;

    dist[start] = 0;
    pq.push(make_pair(start, 0));

    while(!pq.empty()){
        pair <int, int> t = pq.top();
        pq.pop();

        int here = t.first;
        int cur_dist = t.second;
         
        if(dist[here] < cur_dist){
            continue;
        } 

        for(auto adj: graph[here]){
            int there = adj.first;
            int next_dist = cur_dist + adj.second;

            if(next_dist < dist[there]) {
                dist[there] = next_dist;
                pq.push(make_pair(there, next_dist));
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
        int w = 0;

        scanf("%d %d %d", &u, &v, &w);

        graph[u].push_back(make_pair(v, w));
    }


    int start = 0;
    int end = 0;

    scanf("%d %d", &start, &end);

    vector<int> dist = shortest_path(start);

    printf("%d", dist[end]);

    return 0;
}

