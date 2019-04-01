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
    
    for(int i=0; i<dist.size(); i++){
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


    for(int i=1; i<n; i++){

        int parent = 0;
        int child = 0;
        int weight= 0;

        scanf("%d %d %d", &parent, &child, &weight);

        pair <int, int> node1(child, weight);
        pair <int, int> node2(parent, weight);

        graph[parent].push_back(node1);
        graph[child].push_back(node2);

    }

    int u = furthest_node(1);

    int v = furthest_node(u);

    printf("%d", dist[v]);
    return 0;
}
