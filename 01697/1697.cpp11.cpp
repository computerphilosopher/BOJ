#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define MAX_IDX 1000001

using namespace std;

int discoverd[MAX_IDX];

int bfs(const int start, const int dest){

    queue<pair<int,int> > q;

    q.push(pair<int, int> (start, 0));

    int distance = 0;

    while(!q.empty()){

        pair<int, int> here = q.front();

        int h = here.first;
        int t = here.second;
        q.pop();

        if(here.first == dest){
            return t;
        }

        if(h > 0 && !discoverd[h-1])  {
            q.push(pair<int,int>(h-1, t+1));
            discoverd[here.first-1] = true;
        }

        if(here.first < MAX_IDX && !discoverd[h+1])  {
            q.push(pair<int, int>(h+1, t+1));
            discoverd[h+1] = true;
        }

        if(h*2 <= MAX_IDX && !discoverd[h*2])  {
            q.push(pair<int, int> (h*2, t+1));
            discoverd[h*2] = true;
        }

    }

    return -1;

}

int main(){

    int n=0;
    int k=0;

    cin >> n >> k;

    cout << bfs(n, k) << endl;
}

