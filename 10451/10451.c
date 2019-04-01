#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *graph;
bool *visited;

int dfs(int here){

    visited[here] = true;

    if(!visited[graph[here]]){
        dfs(graph[here]);
    }
    else{
        return 1;
    } 
}

int main(){

    int t = 0;

    scanf("%d", &t);

    for(int i=0; i<t; i++){

        int n = 0;

        scanf("%d", &n);

        graph = (int*)calloc(n+1, sizeof(int)); 

        graph[0] = 0;

        for(int i=1; i<=n; i++){
            scanf("%d", &graph[i]);
        }

        visited = (bool*)calloc(n+1, sizeof(bool)); 

        int ans = 0;
        for(int i=1; i<=n; i++){
            if(!visited[i]){
                ans += dfs(i);
            }
        }

        printf("%d\n", ans);

        free(graph);
        free(visited);
    }
}
