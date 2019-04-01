#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector <pair <int, int> > > graph;
vector <int>  dist;

void BFS(int start){

    queue<int> q;
    vector<bool> discovered(graph.size(),false);

    discovered[start] = true;
    dist[start] = 0;

    q.push(start);

    while(!q.empty()){
        int here = q.front();
        q.pop();

        for(auto adj : graph[here]){

            int node = adj.first;

            if(!discovered[node]){

                int weight = adj.second;

                discovered[node] = true;
                dist[node] = dist[here] + weight;

                q.push(node);
            }
        }
    }
}

int furthest_node(int start){

    BFS(start);
    
    int max_node = 0;
    
    for(int i=1; i<dist.size(); i++){
        if(dist[i] > dist[max_node]){
            max_node = i;
        }
    }

    return max_node;
}

int main(){

    int n = 0;

    scanf("%d", &n);

    graph.resize(n+1);
    dist = vector<int>(n+1, 0);

    for(int i=0; i<n; i++){

        int parent= 0;
        scanf("%d", &parent);
         
        while(1){
            int node = 0;
            scanf("%d", &node);

            if(node == -1){
                break;
            }

            int weight= 0;
            scanf("%d", &weight);

            pair <int, int> p1(parent, weight);
            pair <int, int> p2(node, weight);

            graph[parent].push_back(p2);
            graph[node].push_back(p1);
        }
    }

    int u = furthest_node(1);

    int v = furthest_node(u);

    printf("%d",dist[v]);

    return 0;
}
