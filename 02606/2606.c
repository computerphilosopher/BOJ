#include <stdio.h>
 
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct Graph{
    int v;
    bool **adj;
}Graph;

void init(Graph *g, int vertices){

    int n = vertices+1; 
    g->adj = (bool**)malloc(sizeof(bool*)*(vertices+1));

    g->v = vertices;

    for(int i=0; i<n; i++){
        g->adj[i] = (bool*)malloc(sizeof(bool)*(vertices+1));
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
           g-> adj[i][j]= false;
        }
    }

}


int count=0;

int dfs(int here, Graph *g, bool visited[]){

    count++;

    visited[here] = true;

    int n = (g->v)+1;

    for(int i=1; i<=n; i++){

        if(g->adj[here][i]){
            if(!visited[i]){
                dfs(i, g, visited);
            }
        }
    }

    return count;

}

void destroy(Graph *g){

    for(int i=0; i<g->v; i++){
        free(g->adj[i]);
    }

    free(g->adj);
    
}

int main(){

    int vertices = 0;
    int edges = 0;

    scanf("%d %d", &vertices, &edges);

    Graph graph;

    init(&graph, vertices);

    for(int i=0; i<edges; i++){

        int u = 0;
        int v = 0;

        scanf("%d %d", &u, &v);

        graph.adj[u][v] = true;
        graph.adj[v][u] = true;
    }

    bool visited[vertices];

    memset(visited, false, sizeof(visited));

    int answer = dfs(1, &graph, visited);

    printf("%d", answer-1);

    destroy(&graph);

}