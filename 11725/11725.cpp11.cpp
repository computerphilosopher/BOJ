#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int> > tree;

vector <int> answer;

void level_search(int root){

    vector <bool> discovered(tree.size(), false);
    queue <int> q;

    discovered.push_back(root);
    q.push(root);

    while(!q.empty()){
        int parent = q.front();
        q.pop();

        for(int i=0; i<tree[parent].size(); i++){

            int child = tree[parent][i];
            if(!discovered[child]){
                discovered[child] = true;
                q.push(child);

                answer[child] = parent;
            }
        }

    }
}

int main(){
    int n = 0;

    cin.sync_with_stdio(false);
    cin >> n;

    tree = vector<vector<int> >(n+1);

    answer = vector<int>(n+1, 0);

    for(int i=0; i<n-1; i++){
        int u = 0;
        int v = 0;

        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    level_search(1);

    for(int i = 2; i<=n; i++){
        cout << answer[i] << "\n";
    }

    return 0;
     
}
